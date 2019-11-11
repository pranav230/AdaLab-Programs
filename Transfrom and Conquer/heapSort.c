#include<stdio.h>

void printArr(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

//heapifying for root i and it's subtree also
void heapify(int arr[],int i,int n){
	//printArr(arr,n);
	int big=i;
	int l=2*i+1;
	int r=2*i+2;

	//left child
	if(l<n && arr[l]>arr[i])
		big=l;

	//right child
	if(r<n && arr[r]>arr[big])
		big=r;

	//if root is not the largest in the heap
	if(big!=i){
		//swapping
		arr[i]=(arr[i]+arr[big])-(arr[big]=arr[i]);
		
		//heapify the nested subtree when the nodes are changed
		heapify(arr,big,n);
	}
}

void heapSort(int arr[],int n){
	//for building maxHeap
	for(int i=n/2;i>=0;i--)
		heapify(arr,i,n);

	//exchanging the last element from the root element of the heap and removing it and then again making the maxHeap for it.
	for(int i=n-1;i>=0;i--){
		//swapping
		arr[0]=(arr[0]+arr[i])-(arr[i]=arr[0]);

		//again heapifying the heap we just 
		heapify(arr,0,i);
		// printf("\n");
	}
}

int main(){
	int arr[]={8,7,6,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);

	heapSort(arr,n);
	
	printArr(arr,n);
	return 0;
}