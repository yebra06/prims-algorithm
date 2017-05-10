#ifndef NODE_H
#define NODE_H

#include <vector>


class Node {
	public:
		int index, degree;
		std::vector<int> adj;

		Node(int index = 0);
		void adj_list(int adj);
};

#endif
