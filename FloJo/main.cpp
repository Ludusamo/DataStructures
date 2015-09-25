#include <cstdio>
#include "Link.h"

int main() {
	std::vector<int> deathOrder = josephus(5, 3);
	
	for (int i = 0; i < deathOrder.size(); i++) {
		printf("%i\n", deathOrder[i]);
	}
}
