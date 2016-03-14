#include <stdio.h>
#include <math.h>
#include <vector>
#include <stdlib.h>

double T[1001][1001];
int P[1001][1001];
bool adj[1001][1001];
std::vector< std::pair<int, int> > diags;

void clear_adj() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			adj[i][j] = false;
		}
	}
}

void add_adj(int i, int j) {
	adj[i][j] = true;
	adj[j][i] = true;
}

void add_adj_edge(int N) {
	for (int i = 0; i < N; i++) {
		if (i != N - 1) add_adj(i, i + 1);
		else add_adj(i, 0);
	}	
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

typedef std::vector<Point> VP;

double distance(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double min(double a, double b) {
	return (a <= b) ? a : b;
}

void print_tris(int i, int j) {
	if (j < i + 2) return;
	int k = P[i][j];
	printf("(%i, %i, %i)\n", i, j, k);
	print_tris(i, k);
	print_tris(k, j);
}

void print_diags(int i, int j) {
	if (j < i + 2) return;
	int k = P[i][j];
	if (!adj[i][j]) {
		add_adj(i, j);
		diags.push_back(std::pair<int, int>(i, j));
	}
	if (!adj[j][k]) {
		add_adj(j, k);
		diags.push_back(std::pair<int, int>(j, k));
	}
	if (!adj[i][k]) {
		add_adj(i, k);
		diags.push_back(std::pair<int, int>(i, k));
	}
	print_diags(i, k);
	print_diags(k, j);
}

void solve(VP points) {	
	int n = points.size();
	for (int i = 0; i < points.size(); i++) {
		for (int j = 0; j < points.size(); j++) {
			T[i][j] = 0;
			P[i][j] = -1;
		}
	}
	for (int dist = 0; dist < n; dist++) {
		for (int i = 0; i < n - dist; i++) {
			int j = i + dist;
			if (j < i + 2) T[i][j] = 0.0;
			else {
				T[i][j] = 1000000;
				for (int k = i + 1; k < j; k++) {
					Point p1 = points[i];
					Point p2 = points[k];
					Point p3 = points[j];
					double dists = distance(p1, p2) + distance(p2, p3) + distance(p1, p3);
					double cost = T[i][k] + T[k][j] + dists;
					if (T[i][j] >= cost) {
						T[i][j] = cost;
						P[i][j] = k;
					}
				}
			}
		}
	}

	add_adj_edge(points.size());
	print_diags(0, points.size() - 1);
	FILE *out = fopen("diag.out", "w");
	for (int i = 0; i < diags.size(); i++) {
		fprintf(out, "%d %d\n", diags[i].first, diags[i].second);
	}
	fclose(out);
}

int main() {
	clear_adj();

	int N;
	FILE *in = fopen("diag.in", "r");
	fscanf(in, "%d", &N);

	VP points(N);
	for (int i = 0; i < N; i++) {
		fscanf(in, "%lf %lf", &points[i].x, &points[i].y);
	}

	solve(points);
	return 0;
}
