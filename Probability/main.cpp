#include <Probability.h>

int numTests = 100000;

int main() {
	int count = 0;
	srand(time(NULL));	
	for (int i = 0; i < numTests; i++) {
		if(flip(1,3)) count++;
	}
	printf("%d out of %d\n", count, numTests);

	printf("%d\n", bad_flip());
}
