# include <stdio.h>
# include <stdlib.h>
void swap(int* a, int* b) //function to swap two numbers
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
}
void heapify(int* arr, int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2*i + 1; // left = 2*i + 1 
	int r = 2*i + 2; // right = 2*i + 2   	
	if (l < n && arr[l] > arr[largest]) // If left child is larger than root 
        {largest = l;}   
	if (r < n && arr[r] > arr[largest]) // If right child is larger than largest so far 
        largest = r;   
	if (largest != i)     // If largest is not root 
	{ 
        	swap(&arr[i], &arr[largest]);           
        	heapify(arr, n, largest); // Recursively heapify the affected sub-tree 
	} 
}   
void heapSort(int* arr, int n) // main function to do heap sort 
{ 
	int i;   
	for ( i = n / 2 - 1; i >= 0; i--)  // Build heap (rearrange array) 
		heapify(arr, n, i);       
	for (i=n-1; i>=0; i--) // One by one extract an element from heap 
	{         
        	swap(&arr[0], &arr[i]); // Move current root to end         
        	heapify(arr, i, 0);  // call max heapify on the reduced heap 
	} 
} 
int main()
{
	int n,i;	
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	int *A=(int *)malloc(n*sizeof(int));//allocating memory for the array
	printf("Enter the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);// entering the values of the array
	}
	heapSort(A,n);
	printf("The sorted array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}	
	return 0;
}
