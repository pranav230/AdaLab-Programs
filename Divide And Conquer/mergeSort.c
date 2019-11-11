// C program for Merge Sort
#include<stdlib.h> 
#include<stdio.h> 
  
// Merges two subarrays of arr[]. 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    // Merge the temp arrays back into arr[l..r]
    i = 0; 		// Initial index of first subarray 
    j = 0; 		// Initial index of second subarray 
    k = l; 		// Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of L[], if there are any
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of R[], if there are any 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
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

