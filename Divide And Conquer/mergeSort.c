// C program for Merge Sort
#include<stdlib.h> 
#include<stdio.h> 
  
// Merges two subarrays of arr[]. 
void merge(int arr[], int l, int m, int r) 
{
	//b is the temporary array
    int i,k,j,b[500000];
	i=k=l;
	j=m+1;

	while(i<=m && j<=r)
	{
		if(arr[i]<arr[j])
			b[k++]=arr[i++];
		else
			b[k++]=arr[j++];
	}
	
	// Copy the remaining elements of L[], if there are any
	while(i<=m)
		b[k++]=arr[i++];
	
	// Copy the remaining elements of R[], if there are any 
	while(j<=r)
		b[k++]=arr[j++];

	//copy the elements back to the original array
	for(i=l;i<k;i++)
		arr[i]=b[i];
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    {  
        int m = (l+r)/2; 
  
        // Sort first and second halves 
        mergeSort(arr,l,m); 
        mergeSort(arr,m+1,r); 

        merge(arr, l, m, r); 
    } 
} 
  
// Function to print an array
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
	int n;
	printf("Enter the size of the array:");
	scanf("%d",&n);
    int arr[n]; 
    
    printf("Enter the elements of the array one by one:\n");
    for(int i=0;i<n;i++)
    	scanf("%d",&arr[i]); 
  
    printf("Given array is \n"); 
    printArray(arr,n); 
  
    mergeSort(arr,0,n - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr,n); 
    return 0; 
} 

