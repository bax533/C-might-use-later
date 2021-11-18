#include "Vertex.hpp"

#include <map>
#include <vector>
#include <queue>
#include <unordered_set>

class Graph
{
private:
	std::map<Vertex, std::vector<Edge> > data;


public:
	Graph() = default;

	void removeVertex(Vertex v);


	void addEdge(int a, int b, int w);
	void addEdge(Vertex a, Vertex b, int w);

	void removeEdge(Vertex a, Vertex b);

	bool findPath(Vertex a, Vertex b);
};