#include <stdio.h>

const int MAX = 100;

void FloydsShortestPath(int graph[MAX][MAX], int numVert);

int main()
{
	int i, j, numVert;
	int graph[MAX][MAX];
	
	printf("Floyd's Shortest Path\n");
	printf("Enter the number of vertices : ");
	scanf("%d",&numVert);
	
	printf("Enter the adjacency matrix :-\n");
	for (i=0; i<numVert; i++)
		for (j=0; j<numVert; j++)
			scanf("%d",&graph[i][j]);
	
	FloydsShortestPath(graph, numVert);
	
	printf("\nAll Pair Shortest Path Matrix\n");
	for (i=0; i<numVert; i++)
	{
		for (j=0; j<numVert; j++)
			printf("%d\t",graph[i][j]);
		printf("\n");
	}
	
	return 0;
}

void FloydsShortestPath(int iaFloyd[MAX][MAX], int numVert)
{
	int i,j,k;
	for (k=0; k<numVert; k++)
		for (i=0; i<numVert; i++)
			for (j=0; j<numVert; j++)
				//if the path from i->k and k->j is smaller than i->j then assign it in the matrix 
				iaFloyd[i][j] = (iaFloyd[i][j] < (iaFloyd[i][k] +iaFloyd[k][j]))? (iaFloyd[i][j]):(iaFloyd[i][k] + iaFloyd[k][j]);
}