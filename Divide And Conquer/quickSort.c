#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fnGenRandInput(int [],int);
void fnDispArr(int [],int);
void swap(int *,int *);
void fnQuickSort(int [],int ,int);
int fnPartition(int[],int ,int);

int main(){
	int num;
	printf("Enter the number of elements to sort:");
	scanf("%d",&num);
	
	int arr[num];
	
	fnGenRandInput(arr,num);
	fnDispArr(arr,num);
	
	fnQuickSort(arr,0,num-1);

	printf("\nSorted array is \n");
	fnDispArr(arr,num);
	printf("\n");
	return 0;
}

void fnGenRandInput(int arr[],int n){
	srand(time(NULL));
	for(int i=0;i<n;i++)
		arr[i]=rand()%1000;
}

void fnDispArr(int arr[],int n){
	for(int i=0i;i<n;i++)
		printf("%d ",arr[i]);
}

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int fnPartition(int arr[],int l,int r){
	int i,j,p;
	p=arr[l];
	i=l;
	j=r+1;
	do{
		do{
			i++;
		}while(arr[i]<p);
		do{
			j--;
		}while(arr[j]>p);
		swap(&arr[i],&arr[j]);
	}while(i<j);
	swap(&arr[i],&arr[j]);
	swap(&arr[l],&arr[j]);
	return j;
}

void fnQuickSort(int arr[],int l,int r){
	int s;
	if(l<r){
		s=fnPartition(arr,l,r);
		fnQuickSort(arr,l,s-1);
		fnQuickSort(arr,s+1,r);
	}
}
