#include<stdio.h>
#include<stdlib.h>

void minimax(int arr[],int low,int high,int *min,int *max){
	if((high-low)==0)							//only one element
	{
		*max=arr[low];
		*min=arr[low];
	}
	else if((high-low)==1)						//only two elements
	{
		if(arr[low]>arr[high]){
			*min=arr[high];
			*max=arr[low];
		}
		else{
			*min=arr[low];
			*max=arr[high];
		}
	}
	else{
		int mid=(low+high)/2,min1,max1,min2,max2;

		minimax(arr,0,mid,&min1,&max1);
		minimax(arr,mid+1,high,&min2,&max2);
		
		if(min1>min2)
			*min=min2;
		else
			*min=min1;
	
		if(max1>max2)
			*max=max1;
		else
			*max=max2;
	}
}

int main(){
	int n;
	printf("Enter the value of n:");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter the elements of the array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int minmax[2];
	
	minimax(arr,0,n-1,minmax,minmax+1);
	
	printf("The smallest element in the array is %d\n",minmax[0]);
	printf("The largest element in the array is %d\n",minmax[1]);
	
	return 0;
}
