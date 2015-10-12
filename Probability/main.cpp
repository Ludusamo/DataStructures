#include <Probability.h>

int main() {
	int count = 0;
	srand(time(NULL));	
	for (int i = 0; i < 10; i++) {
		if(flip(1,3)) count++;
	}
	printf("%d out of 10\n", count);

}
