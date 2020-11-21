/*
Name : ALTAF AHMAD, Roll no: 18MA20005
Implementation of AVL Trees with insertion, deletion, sorting and display of the tree
*/
#include <iostream>
using namespace std;
int power(int x, unsigned int y) // this is the power function, a helper function that helps during printing of the Tree
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
int max(int a, int b) // Max helper function that gives maximum of two numbers
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
struct Node // basic structure for the node of a tree
{
    int val;
    Node *left;
    Node *right;
};
struct Link // a linked list structure that helps in displaying of the tree
{
    int data;
    struct Link *next;
};
struct Link *head = NULL;
void insert(int new_data) //function that adds data to the end of the linked list. This creates a queue type of structure that helps us in printing the tree
{
    struct Link *new_node = (struct Link *)malloc(sizeof(struct Link));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL) // if the list is empty it adds the first element to the list
    {
        new_node->data = new_data;
        new_node->next = NULL;
        head = new_node;
    }
    else // if the list is not empty, then
    {
        Link *temp = new Link;
        temp = head;
        while (temp->next != NULL) //it traverses to the end of the list and then
        {
            temp = temp->next;
        }
        temp->next = new_node; // adds the new node at that point
    }
}
void display(int ht) // function that displays the tree after the values have been put in one by one
{
    struct Link *ptr;
    int n = power(2, ht), i = 0, l;
    int a[n]; //array is created to show the tree
    for (i = 0; i < n; i++)
    {
        a[i] = -111;
    }
    i = 0;
    ptr = head;
    while (ptr != NULL)
    {
        //cout << ptr->data << " ";
        a[i++] = ptr->data; // the values of the linked list are stored in the array for better call
        ptr = ptr->next;
    }
    l = i;
    i = 0;
    for (int k = ht - 1; k >= 0; k--) // creates each line of the display
    {
        for (int m = 0; m < (power(2, k) - 1); m++) // creates the initial blank spaces between the left margin the main values
        {
            cout << " ";
        }
        int pt = ht - k - 1;
        for (int mn = 0; mn < power(2, pt); mn++) // each line will have 2^k values where k is the level. For eg: root level will have 1 element, 1st level will have 2 element, 2nd level will have 4 elements and so on
        {
            if (a[i] != -111)
                cout << a[i++];
            else
            {
                cout << " ";
                i++;
            }

            for (int m = 0; m < (power(2, k + 1) - 1); m++) // creates the space between the letters in each line
            {
                cout << " ";
            }
        }
        cout << "\n\n";
    }
}
class AVLtree // Class of the (Adelson, Velski & Landis), AVL trees
{
private:
    Node *root; // strores the root node

public:
    AVLtree() // constructor function
    {
        root = NULL;
    }
    Node *insertItem(Node *r, int a);  // inserts items in O(log n) time
    void sort(Node *r);                // this actually displays the array in inorder traversal which is the sorted fashion in case of a BST
    int height(Node *r);               // calculates the height of each subtree
    int htDiff(Node *r);               // the hieght difference. in AVL tree this must lie in the range {-1,0,1}
    Node *rr_rotate(Node *r);          //rotates the node right right
    Node *rl_rotate(Node *r);          //rotates the node right left
    Node *ll_rotate(Node *r);          //rotates the node left right
    Node *lr_rotate(Node *r);          //rotates the node left left
    Node *avl_balance(Node *r);        //balances the tree if there is any difference in height of more than 1 or less than 2
    Node *delete_node(Node *r, int k); // deletes the nodde in O(log n) time
    Node *find(Node *r, int k);        // finds a particular node with value k in O(log n) time
    void displ(Node *r, int ht);       // displays the visualization for the final tree in a 2d fashion
};
Node *rut;
Node *AVLtree::find(Node *r, int k) // Searches in the binary tree
{
    if (r->val == k) // if it is found then it is reported
    {
        return r;
    }
    else if (r->val > k) // if the value is less than the node value, then it looks in the left subtree
    {
        find(r->left, k);
    }
    else // else it looks in the right subtree
    {
        find(r->right, k);
    }
}
Node *minValueNode(Node *node) // finds the min values node that is the leftmost and the bottommost node. THis function helps in deletion
{
    Node *current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
void AVLtree::sort(Node *r) // inorder traversal is done which automatically sorts the tree
{
    if (r == NULL)
    {
        return;
    }
    sort(r->left);
    cout << r->val << " ";
    sort(r->right);
}
int AVLtree::height(Node *r) // finds the height of the subtree
{
    int ht = 0;
    if (r != NULL)
    {
        ht = max(height(r->left), height(r->right)) + 1;
    }
    return ht;
}
int AVLtree::htDiff(Node *r) //checks for the difference in height of the left and right subtree
{
    if (r == NULL)
    {
        return 0;
    }
    return (height(r->left) - height(r->right));
}
Node *AVLtree::ll_rotate(Node *r) //this does the left left rotation
{
    /*
//                          r                                                            temp
//                         /  \                                 \                        /  \  
//                       temp  k                              ===|                      l    r
//                       /  \                                   /                           / \
//                      l    m                                                             m   k
    */
    Node *temp;
    temp = r->left;
    r->left = temp->right;
    temp->right = r;
    return temp;
}
Node *AVLtree::lr_rotate(Node *r)
{
    Node *temp;
    temp = r->left;
    r->left = rr_rotate(temp); // does rr rotate on the left part
    return (ll_rotate(r));     // and then ll rotate on the parent
}
Node *AVLtree::rr_rotate(Node *r) // does the right right rotation
{
    /*
                                          temp                                                        r
                                          /  \                               /                       /  \  
                                          r   k                             |===                    l    temp
                                        /  \                                 \                           / \
                                       l    m                                                           m   k
    */
    Node *temp;
    temp = r->right;
    r->right = temp->left;
    temp->left = r;
    return temp;
}
Node *AVLtree::rl_rotate(Node *r)
{
    Node *temp;
    temp = r->right;
    r->right = ll_rotate(temp); // does ll rotate on the right part
    return rr_rotate(r);        // and then rr rotate on the parent
}
Node *AVLtree::avl_balance(Node *r) // balances the left and right side through right and left rotations
{
    if (htDiff(r) > 1) // if the left side has more height than the right subtree then it does this
    {
        if (htDiff(r->left) > 0)
            r = ll_rotate(r);
        else
        {
            r = lr_rotate(r);
        }
    }
    else if (htDiff(r) < -1) // if the right side has more height than the left subtree then it does this
    {
        if (htDiff(r->right) > 0)
            r = rl_rotate(r);
        else
        {
            r = rr_rotate(r);
        }
    }
    return r;
}
Node *AVLtree::insertItem(Node *r, int a) //insertion of items in O(log n) time is done
{
    if (r == NULL) // if there is no elements in the tree, then it adds the root element. After that it adds the leaf nodes
    {
        r = new Node;
        r->val = a;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    else if (r->val > a) // if the value is less than the current val of the node, then a place on the left subtree is searched
    {
        r->left = insertItem(r->left, a);
        r = avl_balance(r);
    }
    else // otherwise a place on the right subtree is searched
    {
        r->right = insertItem(r->right, a);
        r = avl_balance(r);
    }
    return r;
}
Node *AVLtree::delete_node(Node *r, int k) // This is the Delete node function. It deletes a particular node in O(log n) time
{
    if (r == NULL) // if there is no tree that is it is emppty it just returns the NULL pointer
    {
        return r;
    }
    if (k > r->val) // if the value is greater than the value at the current node then it searches in right subtree for the known values
    {
        r = delete_node(r->right, k);
    }
    else if (k < r->val) // if the value is lesser than the value at the current node then it searches in left subtree for the known values
    {
        r = delete_node(r->left, k);
    }
    else //it will delete this node
    {
        if ((r->left == NULL) || (r->right == NULL)) // if the node has only one child or no children then
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) // or no child
            {
                temp = r;
                r = NULL;
            }
            else //only one child
            {
                *r = *temp;
                free(temp);
            }
        }
        else
        {
            Node *temp = minValueNode(r->right);
            r->val = temp->val;
            r->right = delete_node(root->right, temp->val);
        }
    }
    if (r == NULL)
    {
        return r;
    }
    int balance = htDiff(r);                     //
    if ((balance > 1) && (htDiff(r->left) >= 0)) // Left Left Case
    {
        return ll_rotate(r);
    }
    if ((balance > 1) && (htDiff(r->left) < 0)) // Left Right Case
    {
        r->left = rr_rotate(r->left);
        return ll_rotate(r);
    }
    if ((balance < -1) && (htDiff(r->right) <= 0)) // Right Right Case
    {
        return rr_rotate(r);
    }
    if ((balance < -1) && (htDiff(r->right) > 0)) // Right Left Case
    {
        r->right = ll_rotate(r->right);
        return rr_rotate(r);
    }
    return r;
}

void AVLtree::displ(Node *r, int ht) // Makes the 2d visualization of the AVL tree
{
    int data;
    Node *init = r;
    insert(r->val); // inserts the root element into the linked list
    Link *current = head;
    int u = 1;
    while (u < power(2, ht - 1)) // this moves the current pointer to the pre-final layer of the tree so that all the leafs can be counted
    {
        u++;
        //cout<<u<<" ";
        if (current->data == -111) // -111 is used as a special constant to see if that particular node is NULL
        {
            current = current->next;
            continue;
        }
        data = current->data;
        init = find(r, data);   // it finds the pointer to the Node where the current data point is residing
        if (init->left == NULL) // if the left child is empty
        {
            insert(-111); // then to signify that it stores -111 as specified earlier. A special constant in line 333
            //li.additem(-111);
        }
        else //else if the child is non empty, it's value is appended at the end of the linked list which will be checked later
        {
            //cout << "Left value is " << init->left->val << endl;                  so, if a tree is like this
            insert(init->left->val); //                                                          4
        }                            //                                                       /    \
            //li.additem(init->left->val);                                                  2       6
        //                                                                                 / \     /  \
           //                                                                            1   3        7
        if (init->right == NULL) // similar case for the right child as well        , the numbers stored in the linked list will be
        {                        //                                                                                 4, 2 , 6, 1, 3, -111,7
            //li.additem(-111);                                                             The -111 will be taken care of during printing of the tree.
            insert(-111); //                                                              Currently, our main goal is to store the values of the tree level by level
        }
        else
        {
            //cout << "Right value is " << init->right->val << endl;
            //li.additem(init->right->val);
            insert(init->right->val);
        }
        current = current->next;
    }
    display(ht); // once the linked list is stored, this function prints the table using help of arrays
}
int main()
{
    AVLtree avl;
    int arr[] = {10, 11, 12, 13, 14, 3, 6, 7, 8, 16, 17,  18, 1, 2, -4, -6,  20, 9, 4, 5}, n;
    n = sizeof(arr) / sizeof(arr[0]); // calculates the size of the array
    cout << "The Size of the array is :" << n << " \n";
    for (int i = 0; i < n; i++)
    {
        rut = avl.insertItem(rut, arr[i]); // the items of the array are inserted into the tree one by one. One insertion takes O(log n) time
    }
    //rut = avl.delete_node(rut,4); //currently the deletion function is not working properly but I have tried to implement it fully in O(log n). there is some segementation fault coming in the middle
    int ht = avl.height(rut); // gives the hight of the AVL tree. It will always be of the order O(logn)
    cout << "The Sorted Array is :";
    avl.sort(rut); // prints the sorted array. The sorting is done in O(nlogn) time
    cout << "\nThe representation of the AVL Tree in 2d form is \n\n";
    avl.displ(rut, ht); //  Prints the given AVL tree depicting its tree structure. Tree representations upto level 5 are properly represented visually
}
