#include "node.h"

#include <iostream>


Node::Node( int index ) {
    this->index = index;
    degree = 0;
}

void Node::adj_list( int adj ) {
    this->adj.push_back(adj);
}
