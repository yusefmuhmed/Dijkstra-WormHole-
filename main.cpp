#include <stdio.h>
#include <limits.h>
#define V 4
#define INFINITY 9999
int minDistance(int dist[],
                bool visited[])
{

    // Initialize min value
    int min = INFINITY, index;

    for (int v = 0; v < V; v++)
        if (visited[v] == false &&
                   dist[v] <= min)
            min = dist[v],
            index = v;

return index;
}

// Function to print shortest
// path from source to j
// using parent array
void printPath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    printf("%d", j);
}

// A utility function to print
// the constructed distance
// array
int printSolution(int src,int dist[], int n,
                      int parent[])
{
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        printf("\n%d -> %d \t\t %d \t\t %d ",
                      src, i, dist[i], src);
        printPath(parent, i);
    }
}


void dijkstra(int graph[V][V], int src)
{

    int dist[V];

    // sptSet[i] will true if vertex
    // i is included / in shortest
    // path tree or shortest distance
    // from src to i is finalized
    bool visited[V];

    // Parent array to store
    // shortest path tree
    int parent[V];

    // Initialize all distances as
    // INFINITY and visited as false
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INFINITY;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
     dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        //u is always equal to src in first iteration.
        int u = minDistance(dist, visited);

        // Mark the picked vertex
        // as processed
        visited[u] = true;

        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is
            // not in visited, there is
            // an edge from u to v, and
            // total weight of path from
            // source to v through u is smaller
            // than current value of
            // dist[v]
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }


    printSolution(src,dist, V, parent);
}

int main()
{

    printf("You Entered a %d planet\n",V);
    int src;
    printf("Enter a source planet\n");
    scanf("%d",&src);
    printf("Enter infinity value (unknown weight) as 9999\n");
	int graph[V][V];
	 for(int i=0; i<V; i++) {
      for(int j=0;j<V;j++) {
         printf("Enter a Matrix of a adjacency Graph [%d] [%d]:", i, j);
         scanf("%d", &graph[i][j]);
      }
   }
	dijkstra(graph,src);
	return 0;
}

