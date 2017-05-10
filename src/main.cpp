/*
    Author: Alfredo Yebra Jr.
    Date: April 18, 2016
    Description: Implementation of Prim's algorithms to find minimum spanning tree.
    The spanning tree is a tree that has all the vertices of the graph connected by some edges.
    If the graph has n vertices, the spanning tree will have n-1 edges.
*/

#include "edge.h"
#include "graph.h"
#include "node.h"

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>


int main(int argumentCount, char** argumentVector) {

	/// Open file and assert existence.
	ifstream graph_file("graph.txt");
	if (!graph_file.good()) {
		cout << "Error opening file. Program ended.";
		exit(1);
	}

	/// Read file. Number of edges is first value, amount of vertices is second value.
	int node_count, edge_count;
	vector<int> graph_data;
	graph_file >> node_count >> edge_count;

	/// Read in rest of file and create a Graph object.
    Graph G(node_count, edge_count);
	int edge1, edge2, weight;
	for (int i = 0; i < edge_count; i++) {
		graph_file >> edge1 >> edge2 >> weight;
		G.set_data(i, edge1, edge2, weight);
	}
	
	/// Display graph data, close graph_file, and end program.
	G.display(cout);
	G.prims();
	graph_file.close();
	return 0;
}
