#include <cstdio>
#include <tree.h>

int main() {
	Tree tree;
	tree.set("Brendan", 1);
	Tree::It it = tree.lo() + 1;
	printf("%lf\n", *it);
	return 0;
}
