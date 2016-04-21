#include "graph.h"
#include "edge.h"
#include "node.h"

using namespace std;

#include <iostream>
#include <vector>


/*
	Graph constructor that recieves number of nodes and edges and,
	Loads number of edges and nodes into vectors.
	Remember that if there are n nodes, there is n-1 edges.
*/
Graph::Graph( int node_count, int edge_count ) {
	this->node_count = node_count;
	this->edge_count = edge_count;
	for ( int e = 0, n = 0; n < node_count; e++, n++ ) {
	    edges.push_back( Edge(e) );
	    nodes.push_back( Node(n) );
	}
}

/*
	Read in rest of graph_file define node and edge attributes.
	edge1 and edge2 are adjacent to each other hence edge2 and edge1 are adjacent.
	Note that this is an undirected graph, edge1 is in edge2 adjacency list and vice versa.
*/
void Graph::set_data( int index, int end1, int end2, int weight ) {
	edges[index].edge_set( end1, end2, weight);
	nodes[end1].adj.push_back(end2);
	nodes[end2].adj.push_back(end1);
}

/// Overloaded ostream operator to display the graph data.
void Graph::display( ostream &out ) const {

	/// Display node data.
	out << "\nNodes: " << node_count << "\nEdges: " << edge_count << endl << endl;
    for ( int i = 0; i < node_count; i++ ) {
        out << "Node " << nodes[i].index << " is adjacent with nodes: ";
        for ( int j = 0; j < nodes[i].adj.size(); j++ )
            out << nodes[i].adj[j] << ", ";
        out << endl;
    }

    /// Display edge set.
    out << "\nEdge Set = { ";
    for ( int i = 0; i < edge_count; i++ )
    	out << "(" << edges[i].end1 << ", " << edges[i].end2 << "), ";
    		out << "}" << endl << endl;

    /// Display edge data.
    for ( int i = 0; i < edge_count; i++ )
    	out << "Edge " << i << " connects nodes " << edges[i].end1 << " and " 
    		<< edges[i].end2 << " with cost " << edges[i].weight << endl;
    out << endl;
}


void Graph::prims() {
	const int NODES = node_count;
	int total_weight = 0;
	int current = 0;
	vector<int> touched;
	vector<int> untouched;

	/// Initizlize nodes to high value.
	for ( int i = 0; i < NODES; i++ )
		untouched.push_back(i);

	/// Initialize first to 0;
	untouched[0] = 0;
}






