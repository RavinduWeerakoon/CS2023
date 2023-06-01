#include <bits/stdc++.h>
using namespace std;

int minDistance(int dist[], bool sptSet[], int arr_size)
{

  
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < arr_size; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

//to print the distance array
void printSolution(int dist[], int length)
 {   
    int total = 0;
   

	for (int i=0;i<length;i++){
		cout << i << "--" << dist[i] << endl;
        total += dist[i];
    }

    cout << "Average time for the Ambulances  "<< (double)total/5 << endl;
}


void dijkstra(vector<vector<int>> graph, int src, int city_count)
{   
    int n_cities = (int) graph[0].size();
	int dist[n_cities]; //holds the distance from src to i

	bool sptSet[n_cities]; //keep track of the nodes which has the shortest paths
					
	for (int i = 0; i < n_cities; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < n_cities; count++) {
		
		int u = minDistance(dist, sptSet, city_count);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < n_cities; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	
	printSolution(dist, city_count);
}





int main(){

    int m_size = 6;

    vector<vector<int>> paths = {{0,10,0,0,15,5},
                                 {10,0,10,30,0,0},
                                 {0,10,0,12,5,0},
                                 {0,30,12,0,0,20},
                                 {15,0,5,0,0,0},
                                 {5,0,0,20,0,0}};
    for(int i=0;i<6;i++){
    cout << "Source as node "<<i<<endl;
    dijkstra(paths, i, m_size);
    cout << "\n\n";
    }
    return 0;    

}