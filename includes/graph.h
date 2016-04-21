#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "node.h"

#include <iostream>
#include <vector>


class Graph {

	public:
		int node_count;
		int edge_count;
		std::vector<Edge> edges;
		std::vector<Node> nodes;
		Graph( int node_count = 0, int edge_count = 0 );
		void set_data( int index, int edge1, int edge2, int weight );
		void prims();
		void display( std::ostream &out ) const;

};


#endif