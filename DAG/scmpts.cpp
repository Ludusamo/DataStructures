#include <stdio.h>
#include <vector>
#include <stack>

typedef std::vector< std::vector<int> > VVI;
typedef std::vector<bool> VB;

class Graph {
public:
	Graph(int n_v);

	void add_edge(int f, int t);
	void find_strong_components();
	VVI find_component_arcs();

	VVI get_str_comp();
private:
	int num_vert;
	VVI edges;
	VVI str_comp;
	std::vector<int> component_members;

	void fill(int vertice, VB &visited, std::stack<int> &stack);
	void visit(int vertice, VB &visited);
	Graph get_transpose();
};

Graph::Graph(int n_v) {
	this->num_vert = n_v;
	for (int i = 0; i < n_v; i++) {
		edges.push_back(std::vector<int>());
		component_members.push_back(-1);
	}
}

VVI Graph::get_str_comp() {
	return str_comp;
}

void Graph::add_edge(int f, int t) {
	edges[f].push_back(t);
}

void Graph::find_strong_components() {
	std::stack<int> stack;

	VB visited;
	for (int i = 0; i < num_vert; i++)
		visited.push_back(false);

	for (int i = 0; i < num_vert; i++) {
		if (!visited[i]) fill(i, visited, stack);
	}

	Graph transpose = get_transpose();

	for (int i = 0; i < num_vert; i++) {
		visited[i] = false;
	}

	while (!stack.empty()) {
		int vert = stack.top();
		stack.pop();

		if (!visited[vert]) {
			transpose.str_comp.push_back(std::vector<int>());
			transpose.visit(vert, visited);
		}
	}
	str_comp = transpose.str_comp;
	component_members = transpose.component_members;
}

VVI Graph::find_component_arcs() {
	VVI component_arcs;
	for (int i = 0; i < str_comp.size(); i++) {
		component_arcs.push_back(std::vector<int>(str_comp.size()));
	}

	for (int s = 0; s < str_comp.size(); s++) {
		for (int j = 0; j < str_comp[s].size(); j++) {
			std::vector<int>::iterator i;		
			for (i = edges[str_comp[s][j]].begin(); i < edges[str_comp[s][j]].end(); ++i) {
				if (component_members[*i] != component_members[str_comp[s][j]]) {
					if (component_arcs[s][component_members[*i]] == 0) {
						component_arcs[s][component_members[*i]] = 1;
					}
				}
			}
		}
	}

	return component_arcs;
}

void Graph::fill(int vertice, VB &visited, std::stack<int> &stack) {
	visited[vertice] = true;

	std::vector<int>::iterator i;
	for (i = edges[vertice].begin(); i != edges[vertice].end(); ++i) {
		if (!visited[*i])
			fill(*i, visited, stack);
	}

	stack.push(vertice);
}

void Graph::visit(int vertice, VB &visited) {
	visited[vertice] = true;

	str_comp[str_comp.size() - 1].push_back(vertice);
	component_members[vertice] = str_comp.size() - 1;

	std::vector<int>::iterator i;
	for (i = edges[vertice].begin(); i != edges[vertice].end(); ++i) {
		if (!visited[*i])
			visit(*i, visited);
	}
}

Graph Graph::get_transpose() {
	Graph g(num_vert);
	for (int v = 0; v < num_vert; v++) {
		std::vector<int>::iterator i;
		for (i = edges[v].begin(); i < edges[v].end(); ++i) {
			g.edges[*i].push_back(v);
		}
	}
	return g;
}

int main() {
	int n, m;
	FILE *in = fopen("scmpts.in", "r");
	fscanf(in, "%d %d", &n, &m);

	Graph g(n);	
	for (int i = 0; i < m; i++) {
		int f, t;
		fscanf(in, "%d %d", &f, &t);
		g.add_edge(f, t);
	}
	fclose(in);
	
	g.find_strong_components();	

	VVI str_comp = g.get_str_comp();

	VVI component_arcs = g.find_component_arcs();

	FILE *out = fopen("scmpts.out", "w");
	fprintf(out, "%d\n", str_comp.size());
	for (int i = 0; i < str_comp.size(); i++) {
		fprintf(out, "%d", str_comp[i].size());
		if (i != str_comp.size() - 1) fprintf(out, " ");
	}
	fprintf(out, "\n");
	for (int i = 0; i < str_comp.size(); i++) {
		for (int j = 0; j < str_comp[i].size(); j++) {
			fprintf(out, "%d ", str_comp[i][j]);
			printf("%d ", str_comp[i][j]);
		}
		fprintf(out, "\n");
		printf("\n");
	}

	fprintf(out, "%d\n", component_arcs.size() - 1);
	for (int i = 0; i < component_arcs.size(); i++) {
		for (int j = 0; j < component_arcs[i].size(); j++) {
			if (component_arcs[i][j] == 1) {
				printf("%d to %d\n", i, j);	
				fprintf(out, "%d %d\n", i, j);
			}
		}
	}

	return 0;
}
