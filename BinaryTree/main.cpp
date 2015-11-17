#include <cstdio>
#include <tree.h>

int main() {
	Tree tree;
	tree.set("Brendan", 1);
	Tree::It it = tree.hi();
	printf("%lf\n", *it);
	return 0;
}
