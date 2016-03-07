#include <stdio.h>
#include <math.h>
#include <vector>

bool adj[1001][1001];

void add_edge(int i, int j) {
	if (i == -1) return;
	adj[i][j] = true;
	adj[j][i] = true;
}

void rem_edge(int i, int j) {
	if (i == -1) return;
	adj[i][j] = false;
	adj[j][i] = false;
}

class Point {
public:
	Point() {}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double x, y;
};

class Edge {
public:
	Edge(){}
	Edge(Point p1, Point p2) {
		this->p1 = p1;
		this->p2 = p2;
	}
	Edge(Point p1, Point p2, int pi1, int pi2) {
		this->p1 = p1;
		this->p2 = p2;
		this->pi1 = pi1;
		this->pi2 = pi2;
	}
	int pi1, pi2;
	Point p1, p2;
};

typedef std::vector<Point> VP;
typedef std::vector<Edge> VE;

double dist(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double calc_cost_edge(Edge e) {
	return dist(e.p1, e.p2);
}

double calc_cost_set_edges(VE e) {
	double cost = 0;
	for (int i = 0; i < e.size(); i++) {
		cost += calc_cost_edge(e[i]);
	}
	return cost;
}

VE min(VE a, VE b) {
	return (calc_cost_set_edges(a) <= calc_cost_set_edges(b)) ? a : b;
}

bool is_adj_to(int i, int j) {
	printf("%i %i: %i\n", i, j, adj[i][j]);
	return adj[i][j];
}

Edge determine_edge(VP points, int i, int j, int k) {
	int N = points.size();
	Edge e = Edge(points[0], points[0], -1, -1);
	if (is_adj_to(i, j) && is_adj_to(i, k)) {
		if (!is_adj_to(j, k)) e = Edge(points[j], points[k], j, k);
	} else if (is_adj_to(i, j) && is_adj_to(j, k)) {
		if (!is_adj_to(i, k)) e = Edge(points[i], points[k], i, k);
	} else if (is_adj_to(i, k) && is_adj_to(j, k)) {
		if (!is_adj_to(i, j)) e = Edge(points[i], points[j], i, j);
	}
	add_edge(e.pi1, e.pi2);
	return e;
}

void reset_adj(int N, VE edges) {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (i + 1 != j && i - 1 != j) 
				rem_edge(i, j);
	add_edge(0, N-1);
	for (int i = 0; i < edges.size(); i++) {
		add_edge(edges[i].pi1, edges[i].pi2);
	}
}

VE solve(VP points, int i, int j) {
	VE edges;
	if (j < i + 2)
		return edges;
	edges.push_back(Edge(Point(0, 0), Point(1000000, 0), -1, -1));
	for (int k = i + 1; k < j; k++) {
		if (i == 0 && j == points.size() - 1) reset_adj(points.size(), VE());
		VE edges1 = solve(points, i, k);
		printf("Edges1 Size: %i\n", edges1.size());
		VE edges2 = solve(points, k, j);
		printf("Edges2 Size: %i\n", edges2.size());
		VE edges_new;
		printf("Triangle: %i %i %i\n", i, j, k);
		Edge e = determine_edge(points, i, j, k);
		if (e.pi1 != -1)
			edges_new.push_back(e);

		for (int i = 0; i < edges1.size(); i++) edges_new.push_back(edges1[i]);
		for (int i = 0; i < edges2.size(); i++) edges_new.push_back(edges2[i]);

		printf("Edges_new Size: %i\n\n", edges_new.size());
		for (int i = 0; i < edges_new.size(); i++) {
			
			printf("(%i -> %i)\n", edges_new[i].pi1, edges_new[i].pi2);
			//printf("P1:(%lf, %lf) P2:(%lf, %lf)\n", edges_new[i].p1.x, edges_new[i].p1.y,edges_new[i].p2.x,edges_new[i].p2.y);
		}
		edges = min(edges, edges_new);
		reset_adj(points.size(), edges);
		printf("%lf\n\n", calc_cost_set_edges(edges));
	}
	return edges;
}

int main() {
	int N;
	FILE *in = fopen("diag.in", "r");
	fscanf(in, "%d", &N);

	VP points(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) adj[i][j] = false;
	for (int i = 0; i < N; i++) {
		fscanf(in, "%lf %lf", &points[i].x, &points[i].y);
		if (i != N - 1) add_edge(i, i+1);
		else add_edge(i, 0);
	}
	
	VE edges = solve(points, 0, N-1);
	
	FILE *out = fopen("diag.out", "w");
	for (int i = 0; i < edges.size(); i++) {
		printf("%i %i\n", edges[i].pi1, edges[i].pi2);
		fprintf(out, "%i %i\n", edges[i].pi1, edges[i].pi2);
	}
	printf("Final: %i %lf\n", edges.size(), calc_cost_set_edges(edges));
	return 0;
}
