#include <Probability.h>

int64_t numTests = 10000;

int main() {
	int64_t count = 0;
	srand(time(NULL));	
	for (int64_t i = 0; i < numTests; i++) {
		printf("%lld\n", i);
		if(good_flip()) count++;
	}
	printf("%lld out of %lld\n", count, numTests);
}
