//Used for finding the minimum cost spanning tree

//Input : Weighted graph 
//Output: Minimum cost spanning tree

#include <limits.h> 
#include <stdbool.h> 
#include <stdio.h> 

#define V 5

//for getting the minimum key in the graph which is not visited
int minKey(int key[], bool mstSet[])  
{  
	int min = INT_MAX, min_index;  

	for (int v = 0; v < V; v++)  
		if (mstSet[v] == false && key[v] < min)  
			min = key[v], min_index = v;  

	return min_index;  
}  
  
void printMST(int parent[], int graph[V][V]) 
{ 
    printf("Edge \tWeight\n"); 
    for (int i = 1; i < V; i++) 
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]); 
}  
  
void primMST(int graph[V][V])  
{  
	int parent[V];  

	//it contains minimum weight edge from its parent  
	int key[V];

	//to see if it is included or not
	bool mstSet[V];  

	for (int i = 0; i < V; i++)  
		key[i] = INT_MAX, mstSet[i] = false;  

	key[0] = 0;  
	parent[0] = -1; // First node is always root of MST so it does not have any parent  

	for (int count = 0; count < V - 1; count++) 
	{
		//pick the minimin weighted key from the unincluded nodes
		int u = minKey(key, mstSet);  

		mstSet[u] = true;  

		//update key value and parent index of the adjacent vertices of the picked vertex.  
		//consider only those which are not yet included in tree
		for (int v = 0; v < V; v++)  

			// graph[u][v] is non zero only for adjacent vertices of u  
			// Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
				parent[v] = u, key[v] = graph[u][v];  
	}

	printMST(parent, graph);  
}  

int main()  
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },  
						{ 2, 0, 3, 8, 5 },  
						{ 0, 3, 0, 0, 7 },  
						{ 6, 8, 0, 0, 9 },  
						{ 0, 5, 7, 9, 0 } };  

	primMST(graph);  

	return 0;  
}