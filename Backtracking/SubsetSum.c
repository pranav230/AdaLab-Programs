#include <stdio.h>

const int MAX = 100;
int size,top=-1;

//getting the information from the user
void getInfo(int *size,int set[])
{
	int i;
	
	printf("Enter the maximum number of elements : ");
	scanf("%d",size);
	printf("Enter the weights of the elements : \n");
	
	for (i=1; i<=*size; i++)
		scanf("%d",&set[i]);
}

void push(int data,int stk[])
{
	stk[++top] = data;
}

void pop()
{
	top--;
}

void display(int stk[])
{
	static int count=0;
	int i;
	printf("\nSolution %d is\n{ ",++count);
	
	for (i=0; i<=top; i++)
		printf("%d ",stk[i]);
	printf("}\n");
}

int fnFindSubset(int pos, int sum,int stk[],int set[])
{
	int i;
	static int foundSoln = 0;
	
	if (sum>0)
	{
		for (i=pos; i<=size; i++)
		{
			push(set[i],stk);
			fnFindSubset(i+1, sum - set[i],stk,set);
			pop();
		}
	}
	
	if (sum == 0)
	{
		display(stk);
		foundSoln = 1;
	}
	
	return foundSoln;
}

int main(void)
{
	int i,sum;
	int stk[MAX], set[MAX];
	
	getInfo(&size,set);
	
	printf("Enter the total required weight : ");
	scanf("%d",&sum);
	
	if (!fnFindSubset(1, sum,stk,set))
		printf("\n\nThe given problem instance doesnt have any solution.\n");
	else
		printf("\n\nThe above-mentioned sets are the required solution to the given instance.\n");
	return 0;
}