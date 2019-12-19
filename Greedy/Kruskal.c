//To find the minimum cost spanning tree

//Input : Edges of the graph
//Output: Minimum spanning tree

#include <stdio.h>

const int MAXNODES = 10;
const int INF = 9999;

struct edge
{
	int u, v, cost;
};

//for taking the input of the graph
void fnInputGraph(int m,struct edge e[])
{
	int i, j, k, cost;
	
	for(k=0; k<m; k++)
	{
		printf("Enter edge and cost in the form u, v, w : \n");
		scanf("%d%d%d",&i,&j,&cost);
		e[k].u = i;
		e[k].v = j;
		e[k].cost = cost;
	}
}

//to find the parent of v
int fnFindParent(int v, int parent[])
{
	//parent[v]==v when it is the root node
	while (parent[v] != v)
		//if v != parent[v] then it means that it has some other parent 
		//so we initialize it with its parent and then find the parent of the parent of v
		//at last, we will get the root for that subtree
		v = parent[v];
	return v;
}

//unite two vertices and add to the MST by making the small one parent of greater one
void fnUnion_ij(int i, int j, int parent[])
{
	if(i < j)
		parent[j] = i;
	else
		parent[i] = j;
}

//find the smallest edge in the edge group which has not been added to the MST
//if the edge is added to the MST then it will be INF
int fnGetMinEdge(struct edge e[], int n)
{
	int i, small, pos;
	small = INF;
	pos = -1;
	
	for(i=0; i<n; i++)
	{
		if(e[i].cost < small)
		{
			small = e[i].cost;
			pos = i;
		}
	}
	return pos;
}


void kruskal(int n,struct edge e[], int m)
{
	int i, j, count, k, sum, u, v, t[MAXNODES][2], pos;
	int parent[MAXNODES];
	
	count = 0;
	k = 0;
	sum = 0;
	
	//first initialize the parents with themselves because every node is its own parent
	for(i=0; i<n; i++)
		parent[i] = i;

	//will go till the edges are (vertex-1)
	while(count != n-1)
	{
		pos = fnGetMinEdge(e,m);
		
		//if there is no edge left
		if(pos == -1)
			break;

		u = e[pos].u;
		v = e[pos].v;
		i = fnFindParent(u,parent);
		j = fnFindParent(v,parent);
		
		//if the parent of u and v are same then it means that the edge which is joining u and v have same parent i.e. there will be a cycle created if this edge is included
		//EX:-   6
		//      / \
		//     8---9
		//here 8 and 9 has same parent so if the edge between 8 and 0 is added to the graph then a cycle will be created in the required MST
		if(i != j)
		{
			t[k][0] = u;
			t[k][1] = v;
			k++;
			count++;
			sum += e[pos].cost;

			//unite the vertex
			fnUnion_ij(i, j, parent);
		}

		//initialize the edge cost as infinity so that it can't be used in finding the minimum edge again
		e[pos].cost = INF;
	}

	//if edges are n-1
	if(count == n-1)
	{
		printf("\nSpanning tree exists");
		printf("\nThe Spanning tree is shown below\n");
		
		for(i=0; i<n-1; i++)
			printf("%d -> %d\n",t[i][0],t[i][1]);
		
		printf("\nCost of the spanning tree : %d",sum);
	}
	else
		printf("\nThe spanning tree does not exist");
} 

int main( int argc, char **argv)
{
	int n = 6, m = 10;
	// struct edge e[10]={{0,1,6},{1,4,3},{4,5,6},{5,3,2},{3,0,5},{0,2,1},{1,2,5},{3,2,5},{4,2,6},{5,2,4}};
	struct edge e[MAXNODES];

	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	printf("Enter the number of edges : ");
	scanf("%d",&m);
	
	fnInputGraph(m, e);
	kruskal(n, e, m);
	
	return 0;
}