//find the shortest path for every vertices from a source vertex

//Input : Weighted adjacency matrix and source vertex if the link is not in between two nodes then enter a big number
//Output: Shortest distance between source vertex and all other vertex

#include<stdbool.h>
#include<stdio.h> 
#include<limits.h>

#define V 9 

//returns the minimum distance vertex which is not included in the tree
int minDistance(int dist[], bool sptSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

int printSolution(int dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
    	printf("%d \t\t %d\n", i, dist[i]); 
} 

void dijkstra(int graph[V][V], int src) 
{ 
	// The output array
	int dist[V];  

	// sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
	bool sptSet[V];  

	for (int i = 0; i < V; i++) 
	    dist[i] = INT_MAX, sptSet[i] = false; 

	// Distance of source vertex is always 0 from itself 
	dist[src] = 0; 

	for (int count = 0; count < V - 1; count++) { 
	    //Pick the minimum distance vertex from the vertices that are not included yet 
	    int u = minDistance(dist, sptSet); 

	    //Mark the picked vertex as processed 
		sptSet[u] = true; 

	    //update the distance of vertices that are connected with picked vertex because all distances are either INT_MAX or greater than the shortest distance from the source vertex 
	    for (int v = 0; v < V; v++) 
	        //Update dist[v] only if is not included in tree and there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v] 
	        if (!sptSet[v] && graph[u][v] && (dist[u] != INT_MAX) && (dist[u] + graph[u][v] < dist[v])) 
	        	dist[v] = dist[u] + graph[u][v]; 
	} 

	printf("\nSource --> %d\n",src);
	printSolution(dist); 
} 

int main() 
{ 
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
	                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
	                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
	                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
	                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
	                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
	                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
	                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
	                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

	for(int i=0;i<V;i++)
		dijkstra(graph,i);

	return 0; 
}