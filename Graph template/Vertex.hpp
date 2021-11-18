#pragma once

#include "bits/stdc++.h"

class Vertex
{
private:
	int id;

public:
	Vertex() = default;

	Vertex(int id)
	:id(id)
	{}

	bool operator<(const Vertex& o) const
	{
		return this->id < o.id;
	}

	bool operator>(const Vertex& o) const
	{
		return this->id > o.id;
	}

	bool operator==(const Vertex& o) const
	{
		return this->id == o.id;
	}

	int getId() const
	{
		return id;
	}
};

namespace std
{
	template <>
	struct hash<Vertex>
	{
		std::size_t operator()(const Vertex& v) const
		{
			using std::size_t;
			using std::hash;

			return hash<int>()(v.getId());
		}
	};
}

class Edge
{
private:
	Vertex v;
	int weight;

public:
	Edge() = default;
	
	Edge(Vertex v, int w)
	:v(v), weight(w)
	{}

	Edge(int id, int w)
	:weight(w)
	{
		v = Vertex(id);
	}

	int getWeight() const
	{
		return weight;
	}

	int getId() const
	{
		return v.getId();
	}

	Vertex getVertex() const
 	{
		return v;
	}

	void setWeight(int w)
	{
		this->weight = w;
	}
};

