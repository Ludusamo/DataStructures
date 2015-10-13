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
	return ((double) (rand() % 10000000) / (double)10000000) < (double) 10 / (double) 100000;
}

bool good_flip() {
	int a, b;
	do {
		a = bad_flip();
		b = bad_flip();
	} while (a == b);
	printf("%d %d\n", a, b);
	return a;
}
