#include <bits/stdc++.h>
using namespace std;


//find the minimum edge value
int minKey(int key[], bool mstSet[], int size)
{

	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < size; v++){
		if (mstSet[v] == false && key[v] < min){
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}


void print_mst(int prev[], vector<vector<int>> graph, int size)
{
	int sum = 0; // to find the sum of edge weights
    cout << "Vertices Weight\n"; 
	for (int i = 1; i < size; i++){
		cout << prev[i] << " -> " << i << " \t"
			<< graph[i][prev[i]] << " \n";
        sum += graph[i][prev[i]];
    }


    cout << "Total weight is " <<sum << endl; 
}


void prims(vector<vector<int>> graph)
{

    int size = (int) graph[0].size();
	//initialize the arrays to keep track of the 
	int parent[size];

	int key[size];

	bool mstSet[size];

	for (int i = 0; i < size; i++){
		key[i] = INT_MAX, mstSet[i] = false;
	}


	key[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < size - 1; count++) {
		

		int u = minKey(key, mstSet, size);

		mstSet[u] = true;


		for (int v = 0; v < size; v++)


			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	
	print_mst(parent, graph, size);
}


int main()
{
	vector<vector<int>> graph = { { 0, 3, 0, 0, 0, 1 },
                                  { 3, 0, 2, 1, 10, 0 },
                                  { 0, 2, 0, 3, 0, 5 },
                                  { 0, 1, 3, 0, 5, 0 },
                                  { 0, 10, 0, 5, 0, 4 },
                                  { 1, 0, 5, 0, 4, 0} };

	
	prims(graph);


	return 0;

}

