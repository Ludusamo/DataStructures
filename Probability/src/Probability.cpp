#include <Probability.h>

bool flip() {
	return (rand() % 2);
}

bool flip(uint64_t a, uint64_t b) {
	double x = (double) a / (double) b;
	for (int i = 0; i < 64; i++) {
		x *= 2;	
		if (flip() == (x > 1)) return (x > 1);
		x = (x > 1) ? x - 1 : x;
	}
	return false;
}

bool bad_flip() {
	uint64_t denominator = rand() % 1000000;
	uint64_t numerator = rand() % denominator;
	return ((double) (rand() % 1000000) / (double)1000000) > (((double) numerator) / ((double) denominator));
}
