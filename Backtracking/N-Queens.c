//row array here gives the position of ith queen in column
//Example :  if the 1st queen is in first cloumn, 2nd queen is in 3rd column, 3rd queen is in 2nd column then,
//           Row[]={0     ,2    ,1}
//                  first third second
//                  col   col   col

#include <stdio.h>
#include <stdlib.h>

const int MAX = 10;
int SolnCount =0;

void fnChessBoardShow(int n, int row[MAX]);
int fnCheckPlace(int KthQueen, int ColNum, int row[MAX]);
int NQueen(int k,int n, int row[MAX]);

int main(void)
{
	int n,i;
	int row[MAX];
	printf("Enter the number of queens : ");
	scanf("%d",&n);

	if (!NQueen(0,n,row))
		printf("No solution exists for the given problem instance." );
	else
		printf("Number of solution for the given problem instance is : %d\n",SolnCount);

	return 0;
}

//here k represents the kth queen,n is the total number of queens and row is a container array
int NQueen(int k,int n, int row[MAX])
{
	int col;
	static int flag;
	for(col=0; col<n; col++)
	{
		if(fnCheckPlace(k,col,row))
		{
			//changes every time when calculating for kth queen
			row[k] = col;
			if(k == n-1)
			{
				fnChessBoardShow(n,row);
				SolnCount++;
				flag = 1;
				return flag;
			}
			//increase the value of k if the (k-1)th queen is in right position
			NQueen(k+1, n, row);
		}
	}
	return flag;
}

//Check if kth queen can be placed in 'Col' column 
int fnCheckPlace(int KthQueen, int Col, int row[MAX])
{
	int i;
	//check the validaton for all the k-1 queens
	for( i=0; i<KthQueen; i++)
	{
		//row[i]==col --> checks if the coloumn of the kth queeen is same as any previous queens
		//abs(row[i]-Col)(Coloumn distance) == abs(i-KthQueen)(row distance) --> checks if the row distance and column distance from the position is same or not, if they are same then it means that it is in same column.
		//if any of the condition is true then it returns false
		if(row[i] == Col || abs(row[i]-Col) == abs(i-KthQueen))
			return 0;
	}
	return 1;
}

//simply print the chessboard after we have found a solution
void fnChessBoardShow(int n, int row[MAX])
{
	int i,j;
	printf("\nSolution #%d \n",SolnCount+1); 
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (j == row[i])
				printf("Q ");
			else
				printf("# ");
		}
		printf("\n");
	}
	printf("\n");
}

