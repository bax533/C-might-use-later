#include "Graph.hpp"

void Graph::removeVertex(Vertex v)
{
	for(auto & [key, val] : data)
	{
		if(key.getId() == v.getId())
		{
			val.clear();
			continue;
		}

		int toRemove = -1;
		for(int i=0; i<val.size(); i++)
			if(val[i].getId() == v.getId())
			{
				toRemove = i;
				break;
			}

		if(toRemove)
			val.erase(val.begin()+toRemove);
	}
}

void Graph::addEdge(int a, int b, int w)
{
	addEdge(Vertex(a), Vertex(b), w);
}

void Graph::addEdge(Vertex a, Vertex b, int w)
{
		if(data.find(a) == data.end())
			data[a] = std::vector<Edge>();
		if(data.find(b) == data.end())
			data[b] = std::vector<Edge>();

	for(Edge& e : data[a])
		if(e.getId() == b.getId())
		{
			e.setWeight(w);
			break;
		}

	for(Edge& e : data[b])
		if(e.getId() == a.getId())
		{
			e.setWeight(w);
			return;
		}


	data[a].push_back(Edge(b, w));
	data[b].push_back(Edge(a, w));
}

void Graph::removeEdge(Vertex a, Vertex b)
{
	if(data.find(a) != data.end())
	{
		int toRemove = -1;
		for(int i=0; i<data[a].size(); i++)
			if(data[a][i].getId() == b.getId())
			{
				toRemove = i;
				break;
			}

		if(toRemove)
			data[a].erase(data[a].begin()+toRemove);
	}

	if(data.find(b) != data.end())
	{
		int toRemove = -1;
		for(int i=0; i<data[b].size(); i++)
			if(data[b][i].getId() == a.getId())
			{
				toRemove = i;
				break;
			}

		if(toRemove)
			data[b].erase(data[b].begin()+toRemove);
	}
}

bool Graph::findPath(Vertex a, Vertex b)
{
	std::queue<Vertex> q;
	std::unordered_set<Vertex> vis;
	q.push(a);

	while(!q.empty())
	{
		Vertex top = q.front();
		q.pop();			

		if(top.getId() == b.getId())
			return true;

		vis.insert(top);
		for(const Edge& e :  data[top])
			if(vis.find(e.getVertex()) == vis.end())
				q.push(e.getVertex());
	}

	return false;
}