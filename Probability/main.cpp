#include <Probability.h>

int main() {
	int count = 0;
	srand(time(NULL));	
	for (int i = 0; i < 100000; i++) {
		if(flip()) count++;
	}
	printf("%d out of 100000", count);
}
