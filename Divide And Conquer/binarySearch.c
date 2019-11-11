#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int l,int h,int key){
	if(h>=l){
		int mid=(l+h)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			binarySearch(arr,0,mid-1,key);
		else
			binarySearch(arr,mid+1,h,key);
	}
	
	return -1;
}

int main(){
	int n,key;
	printf("Enter the value of n:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of the array in ascending order:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the key element you want to find:");
	scanf("%d",&key);
	int a=binarySearch(arr,0,n-1,key);
	if(a==-1)
		printf("Key element is not found in the array\n");
	else
		printf("Key element is found at %d position\n",a+1);
}
