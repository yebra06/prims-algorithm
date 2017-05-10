#ifndef EDGE_H
#define EDGE_H


class Edge {
	public:
		/// Member variables.
		int index;
		int end1;
		int end2;
		int weight;

		/// Member methods.
		Edge(int index = 0);
		void edge_set(int end1, int end2, int weight);
};

#endif
