#include "Graph.hpp"

int main()
{
	Graph g = Graph();

	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 10, 2);

	g.removeEdge(3, 10);

	bool exists = g.findPath(1, 10);
	printf("%d\n", exists);
}