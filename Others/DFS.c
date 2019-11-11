#include<stdio.h>
#include<stdlib.h>

const int MAX=100;

void fndepthfirstserach(int currentvertex, int v[MAX],int g[MAX][MAX],int n);

int main(void)
{
	int i,j,k;
	int visited[MAX];
	int graph[MAX][MAX];
	int numvert,vert;
	
	printf("Enter the no. of vertices: ");
	scanf("%d",&numvert);
	
	for(i=0;i<numvert;i++)
		visited[i]=0;
	
	printf("Enter the adjacency matrix here:\n");
	for(i=0;i<numvert;i++)
		for(j=0;j<numvert;j++)
			scanf("%d",&graph[i][j]);
	
	printf("Enter the source vertex: ");
	scanf("%d",&vert);
	
	fndepthfirstserach(vert-1,visited,graph,numvert);
	
	for(k=0;k<numvert;k++)
	{	
		if(visited[k])
		{
			printf("\n vertex %d reachable\n",k+1);
		}
		else
		{
			printf("\n vertex %d not reachacble\n",k+1);
		}
	}
	return 0;
}

void fndepthfirstserach(int currentvertex,int v[MAX],int g[MAX][MAX],int n)
{
	int i;
	//marking the starting vertex as visited
	v[currentvertex]=1;
	
	for(i=0;i<n;i++)
		//if the vertex that is connected to current vertex is not visited then running DFS for that vertex 
		if(g[currentvertex][i]&& !v[i])
			//here the starting vertex is the non visited vertex
			fndepthfirstserach(i,v,g,n);
}
