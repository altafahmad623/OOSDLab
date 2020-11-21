#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>
typedef struct {
  double x, y;
} point_t, vector_t;


/* Segment attributes */

typedef struct {	
  point_t v0, v1;		/* two endpoints */
  int is_inserted;		/* inserted in trapezoidation yet ? */
  int root0, root1;		/* root nodes in Q */
  int next;			/* Next logical segment */
  int prev;			/* Previous segment */
} segment_t;


/* Trapezoid attributes */

typedef struct {
  int lseg, rseg;		/* two adjoining segments */
  point_t hi, lo;		/* max/min y-values */
  int u0, u1;
  int d0, d1;
  int sink;			/* pointer to corresponding in Q */
  int usave, uside;		/* I forgot what this means */
  int state;
} trap_t;


/* Node attributes for every node in the query structure */

typedef struct {
  int nodetype;			/* Y-node or S-node */
  int segnum;
  point_t yval;
  int trnum;
  int parent;			/* doubly linked DAG */
  int left, right;		/* children */
} node_t;


typedef struct {
  int vnum;
  int next;			/* Circularly linked list  */
  int prev;			/* describing the monotone */
  int marked;			/* polygon */
} monchain_t;			


typedef struct {
  point_t pt;
  int vnext[4];			/* next vertices for the 4 chains */
  int vpos[4];			/* position of v in the 4 chains */
  int nextfree;
} vertexchain_t;


/* Node types */

#define T_X     1
#define T_Y     2
#define T_SINK  3


#define SEGSIZE 200		/* max# of segments. Determines how */
				/* many points can be specified as */
				/* input. If your datasets have large */
				/* number of points, increase this */
				/* value accordingly. */

#define QSIZE   8*SEGSIZE	/* maximum table sizes */
#define TRSIZE  4*SEGSIZE	/* max# trapezoids */


#define TRUE  1
#define FALSE 0


#define FIRSTPT 1		/* checking whether pt. is inserted */ 
#define LASTPT  2


#define INFINITY 1<<30
#define C_EPS 1.0e-7		/* tolerance value: Used for making */
				/* all decisions about collinearity or */
				/* left/right of segment. Decrease */
				/* this value if the input points are */
				/* spaced very close together */


#define S_LEFT 1		/* for merge-direction */
#define S_RIGHT 2


#define ST_VALID 1		/* for trapezium state */
#define ST_INVALID 2


#define SP_SIMPLE_LRUP 1	/* for splitting trapezoids */
#define SP_SIMPLE_LRDN 2
#define SP_2UP_2DN     3
#define SP_2UP_LEFT    4
#define SP_2UP_RIGHT   5
#define SP_2DN_LEFT    6
#define SP_2DN_RIGHT   7
#define SP_NOSPLIT    -1	

#define TR_FROM_UP 1		/* for traverse-direction */
#define TR_FROM_DN 2

#define TRI_LHS 1
#define TRI_RHS 2


#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define CROSS(v0, v1, v2) (((v1).x - (v0).x)*((v2).y - (v0).y) - \
			   ((v1).y - (v0).y)*((v2).x - (v0).x))

#define DOT(v0, v1) ((v0).x * (v1).x + (v0).y * (v1).y)

#define FP_EQUAL(s, t) (fabs(s - t) <= C_EPS)



/* Global variables */

extern node_t qs[QSIZE];		/* Query structure */
extern trap_t tr[TRSIZE];		/* Trapezoid structure */
extern segment_t seg[SEGSIZE];		/* Segment table */


/* Functions */

extern int monotonate_trapezoids(int);
extern int triangulate_monotone_polygons(int, int, int (*)[3]);

extern int _greater_than(point_t *, point_t *);
extern int _equal_to(point_t *, point_t *);
extern int _greater_than_equal_to(point_t *, point_t *);
extern int _less_than(point_t *, point_t *);
extern int locate_endpoint(point_t *, point_t *, int);
extern int construct_trapezoids(int);

extern int generate_random_ordering(int);
extern int choose_segment(void);
extern int read_segments(char *, int *);
extern int math_logstar_n(int);
extern int math_N(int, int);


static int initialise(n)
     int n;
{
  register int i;

  for (i = 1; i <= n; i++)
    seg[i].is_inserted = FALSE;

  generate_random_ordering(n);
  
  return 0;
}



int main(argc, argv)
     int argc;
     char *argv[];
{
  int n, nmonpoly, genus;
  int op[SEGSIZE][3], i, ntriangles;

  if ((argc < 2) || ((n = read_segments(argv[1], &genus)) < 0))
    {
      fprintf(stderr, "usage: triangulate <filename>\n");
      exit(1);
    }

  initialise(n);
  construct_trapezoids(n);
  nmonpoly = monotonate_trapezoids(n);
  ntriangles = triangulate_monotone_polygons(n, nmonpoly, op);

  for (i = 0; i < ntriangles; i++)
    printf("triangle #%d: %d %d %d\n", i, 
	   op[i][0], op[i][1], op[i][2]);

  return 0;
}


  /* Not standalone. Use this as an interface routine */


/* Input specified as contours.
 * Outer contour must be anti-clockwise.
 * All inner contours must be clockwise.
 *  
 * Every contour is specified by giving all its points in order. No
 * point shoud be repeated. i.e. if the outer contour is a square,
 * only the four distinct endpoints shopudl be specified in order.
 *  
 * ncontours: #contours
 * cntr: An array describing the number of points in each
 *	 contour. Thus, cntr[i] = #points in the i'th contour.
 * vertices: Input array of vertices. Vertices for each contour
 *           immediately follow those for previous one. Array location
 *           vertices[0] must NOT be used (i.e. i/p starts from
 *           vertices[1] instead. The output triangles are
 *	     specified  w.r.t. the indices of these vertices.
 * triangles: Output array to hold triangles.
 *  
 * Enough space must be allocated for all the arrays before calling
 * this routine
 */


int triangulate_polygon(ncontours, cntr, vertices, triangles)
     int ncontours;
     int cntr[];
     double (*vertices)[2];
     int (*triangles)[3];
{
  register int i;
  int nmonpoly, ccount, npoints, genus;
  int n;

  memset((void *)seg, 0, sizeof(seg));
  ccount = 0;
  i = 1;
  
  while (ccount < ncontours)
    {
      int j;
      int first, last;

      npoints = cntr[ccount];
      first = i;
      last = first + npoints - 1;
      for (j = 0; j < npoints; j++, i++)
	{
	  seg[i].v0.x = vertices[i][0];
	  seg[i].v0.y = vertices[i][1];

	  if (i == last)
	    {
	      seg[i].next = first;
	      seg[i].prev = i-1;
	      seg[i-1].v1 = seg[i].v0;
	    }
	  else if (i == first)
	    {
	      seg[i].next = i+1;
	      seg[i].prev = last;
	      seg[last].v1 = seg[i].v0;
	    }
	  else
	    {
	      seg[i].prev = i-1;
	      seg[i].next = i+1;
	      seg[i-1].v1 = seg[i].v0;
	    }
	  
	  seg[i].is_inserted = FALSE;
	}
      
      ccount++;
    }
  
  genus = ncontours - 1;
  n = i-1;

  initialise(n);
  construct_trapezoids(n);
  nmonpoly = monotonate_trapezoids(n);
  triangulate_monotone_polygons(n, nmonpoly, triangles);
  
  return 0;
}


/* This function returns TRUE or FALSE depending upon whether the 
 * vertex is inside the polygon or not. The polygon must already have
 * been triangulated before this routine is called.
 * This routine will always detect all the points belonging to the 
 * set (polygon-area - polygon-boundary). The return value for points 
 * on the boundary is not consistent!!!
 */

int is_point_inside_polygon(vertex)
     double vertex[2];
{
  point_t v;
  int trnum, rseg;
  trap_t *t;

  v.x = vertex[0];
  v.y = vertex[1];
  
  trnum = locate_endpoint(&v, &v, 1);
  t = &tr[trnum];
  
  if (t->state == ST_INVALID)
    return FALSE;
  
  if ((t->lseg <= 0) || (t->rseg <= 0))
    return FALSE;
  rseg = t->rseg;
  return _greater_than_equal_to(&seg[rseg].v1, &seg[rseg].v0);
}



