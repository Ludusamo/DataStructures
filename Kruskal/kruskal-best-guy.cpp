#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

class Edge {
public:
	Edge(int f, int t, int w);
	int f, t, w;

	bool operator<(const Edge &e) const;
};

Edge::Edge(int f, int t, int w) {
	this->f = f;
	this->t = t;
	this->w = w;
}

bool Edge::operator<(const Edge &e) const {
	return this->w < e.w;
}

typedef std::vector<Edge> Edges;

class Graph {
public:
	Graph(int n_v);

	void add_edge(int f, int t, int w);
	void sort_edges();
	Edges find_min_span();
private:
	int num_vert;
	std::vector<int> vertices;
	std::vector< std::vector<int> > sets;
	Edges edges;

	void join(int s1, int s2);
	bool joined(int v1, int v2);
};

Graph::Graph(int n_v) {
	this->num_vert = n_v;
	for (int i = 0; i < n_v; i++) {
		vertices.push_back(i);
		std::vector<int> buff;
		buff.push_back(i);
		sets.push_back(buff);
	}
}

void Graph::join(int s1, int s2) {
	int group_from = vertices[s2];
	for (int i = 0; i < sets[group_from].size(); i++) {
		sets[vertices[s1]].push_back(sets[group_from][i]);
		vertices[sets[group_from][i]] = vertices[s1];
	}
}

bool Graph::joined(int v1, int v2) {
	return vertices[v1] == vertices[v2];
}

void Graph::add_edge(int f, int t, int w) {
	edges.push_back(Edge(f, t, w));
}

void Graph::sort_edges() {
	std::sort(edges.begin(), edges.end());
}

Edges Graph::find_min_span() {
	Edges min_span;
	sort_edges();
	for (int i = 0; i < edges.size(); i++) {
		int f = edges[i].f;
		int t = edges[i].t;
		if (!joined(f, t)) {
			join(f, t);
			min_span.push_back(edges[i]);
			if (sets[f].size() == num_vert) break;
		}
	}
	return min_span;
}

struct vert_compare {
	inline bool operator()(const Edge& e1, const Edge& e2) {
		if (e1.f == e2.f)
			return (e1.t < e2.t);
		return (e1.f < e2.f); 
	}
};

int main() {
	FILE *in = fopen("kruskal.in", "r");	
	int n, m;
	fscanf(in, "%i %i", &n, &m);
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int f, t, w;
		fscanf(in, "%i %i %i", &f, &t, &w);
		g.add_edge((f < t) ? f : t, (f < t) ? t : f, w);
	}
	fclose(in);

	Edges min_span = g.find_min_span();

	FILE *out = fopen("kruskal.out", "w");
	fprintf(out, "%i\n", min_span.size());
	std::sort(min_span.begin(), min_span.end(), vert_compare());
	for (int i = 0; i < min_span.size(); i++) {
		fprintf(out, "%i %i\n", min_span[i].f, min_span[i].t);
	}
	fclose(out);
}
