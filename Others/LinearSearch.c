#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[],int l,int r,int key){
	if(l>r)
		return -1;
	if(arr[l]==key)
		return l;
	if(arr[r]==key)
		return r;
	return linearSearch(arr,l+1,r-1,key);
}

int main()
{
	int n,key;
	printf("Enter the value of n:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of the array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the key element you want to find:");
	scanf("%d",&key);
	int a=linearSearch(arr,0,n-1,key);
	if(a==-1)
		printf("Key element is not found in the array\n");
	else
		printf("Key element is found at %d position\n",a+1);
}
