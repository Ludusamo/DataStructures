#include <cstdio>
#include <climits>

#include "Link.h"

int main() {
	std::vector<int32_t> deathOrder = josephus(1000000, 3);
	
	printf("Death Order:\n");
	for (int32_t i = 0; i < deathOrder.size(); i++) {
		printf("%i\n", deathOrder[i]);
	}
}
