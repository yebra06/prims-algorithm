#include "edge.h"

#include <iostream>


Edge::Edge( int index ) {
	this->index = index;
	end1 = 0;
	end2 = 0;
	weight = 0;
}

void Edge::edge_set( int end1, int end2, int weight ) {
	this->end1 = end1;
	this->end2 = end2;
	this->weight = weight;
}