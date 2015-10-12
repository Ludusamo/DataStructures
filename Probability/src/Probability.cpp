#include <Probability.h>

bool flip() {
	return (rand() % 2);
}

bool flip(uint64_t a, uint64_t b) {
	for (int i = 0; i < 64; i++) {
		a *= 2;	
		if (flip() == (a > b)) return (a > b);
		a = (a > b) ? a - b : a;
	}
	return false;
}
