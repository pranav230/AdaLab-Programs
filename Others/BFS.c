#include<stdio.h>
#include<stdlib.h>

#define max 100

int Q[max];
int f=-1;
int r=-1;

void fnBFS(int vertex,int g[max][max],int v[max],int n);
void enqueue(int Q[],int *f,int *r,int data);
int dequeue(int Q[],int *f,int *r);

int empty(int Q[],int f,int r)
{
	return f ==-1?1:0;
}

int main()
{
	int i,j;
	int graph[max][max],visited[max];
	int numvert,startvert;
	
	printf("Enter the number of vertices:");
	scanf("%d",&numvert);
	
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<numvert;i++)
		visited[i]=0;
	
	for(i=0;i<numvert;i++)
		for(j=0;j<numvert;j++)
			scanf("%d",&graph[i][j]);
			
	printf("Enter the starting vertex:");
	scanf("%d",&startvert);
	fnBFS(startvert-1,graph,visited,numvert);
	printf("Vertices which can be reached from vertex %d are:\n",startvert);
	
	for(i=0;i<numvert;i++)
		if(visited[i])
			printf("%d",i+1);
		printf("\n");
	
	return 0;	
}

void enqueue(int Q[],int *f,int *r,int data)
{
	if(*f==((*r+1)%max))
		return;
	
	if(*r==-1)
		*f=*r=0;
	else
		*r=(*r+1)%max;
		
	Q[*r]=data;
	
	return;
}

int dequeue(int Q[],int *f,int *r)
{
	int data;
	if(*f==-1)
		return 0;
	data=Q[*f];
	
	if(*f==*r)
		*f=*r=-1;	
	else
		*f=(*f+1)%max;
		
	return data;
}

void fnBFS(int vertex,int g[max][max],int v[max],int n)
{
	int frontvertex,i;
	
	//marking starting vertex as visited
	v[vertex]=1;
	//adding the starting veretx to the queue
	enqueue(Q,&f,&r,vertex);
	
	//while queue is not empty
	while(!empty(Q,f,r))
	{
		//importing the front vertex
		frontvertex=dequeue(Q,&f,&r);
		
		for(i=0;i<n;i++)
		{
			//if the front vertex is connected to any of the vertex and it is not visited then add it to the queue
			if(g[frontvertex][i] && (!v[i]))
			{
				v[i]=1;
				enqueue(Q,&f,&r,i);
			}
		}
	}
}
