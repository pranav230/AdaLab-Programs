//Remove the comments for a dynamic program

#include <stdio.h>

const int MAX = 10;

int max(int a, int b);
void fnProfitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX]);
void fnSelectItems(int n,int c, int t[MAX][MAX], int w[MAX], int l[MAX]);

int main(void)
{
	int i, j, totalProfit;
	// int weight[MAX];
	// int profit[MAX];
	int capacity;
	int num;
	// int loaded[MAX];
	int table[MAX][MAX];
	
	// printf("Enter the maxium number of objects : ");
	// scanf("%d",&num);
	num=4;

	// printf("Enter the weights : \n");
	// for (i=1; i<=num; i++)
	// {
	// 	printf("\nWeight %d: ",i);
	// 	scanf("%d",&weight[i]);
	// }
	int weight[10]={0,2,1,3,2};

	// printf("\nEnter the profits : \n");
	// for (i=1; i<=num; i++)
	// {
	//  	printf("\nProfit %d: ",i);
	// 		scanf("%d",&profit[i]);
	// }
	int profit[10]={0,12,10,20,15};
	
	// printf("\nEnter the maximum capacity : ");
	// scanf("%d",&capacity);
	capacity=5;
	totalProfit = 0;
	
	// for( i=1; i<=num; i++)
	// 	loaded[i] = 0;
	int loaded[10]={0};

	fnProfitTable(weight,profit,num,capacity,table);
	fnSelectItems(num,capacity,table,weight,loaded);
	
	printf("Profit Matrix\n");
	for (i=0; i<=num; i++)
	{
		for(j=0; j<=capacity; j++)
			printf("\t%d",table[i][j]);
		printf("\n");
	}
	
	printf("\nItem numbers which are loaded : \n{ ");
	for (i=1; i<=num; i++)
	{
		if (loaded[i])
		{
			printf(" %d ",i);
			totalProfit += profit[i];
		}
	}
	printf("}\nTotal Profit : %d\n",totalProfit);
	return 0;
}

int max(int a, int b)
{
	return a>b ? a : b;
}

//function to make profit table 't'
void fnProfitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX])
{
	int i,j;
	for (i=0; i<=n; i++)
	{
		for (j=0; j<=c; j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			else if (j-w[i] < 0)
				t[i][j] = t[i-1][j];
			else
				t[i][j] = max( t[i-1][j], p[i] + t[i-1][j-w[i]]);
		}
	}
}

//function to find out which items are selected and put them into a binary matrix called loaded or 'l' here
void fnSelectItems(int n,int c, int t[MAX][MAX], int w[MAX], int l[MAX])
{
	int i,j;
	i = n;
	j = c;
	
	while (i >= 1 && j >= 1)
	{
		if (t[i][j] != t[i-1][j])
		{
			l[i] = 1;
			j = j - w[i];
			i--;
		}
		else
			i--;
	}
}