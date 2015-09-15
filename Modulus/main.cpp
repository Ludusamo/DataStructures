#include <stdio.h>
#include <climits>
#include "Mod.h"
#include "ExtendedEuclidean.h"
#include "TestCase.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

int64_t mod = 4;
int64_t a = 6;
int64_t b = 23;


void resetVariables(Mod& mod1, Mod& mod2) {
	mod1 = Mod(a);
	mod2 = Mod(b);
}

int main() {	
	FILE *input;
	input = fopen("res/test.in", "r");	
	if (input == NULL) {
		printf("File does not exist!\n");
		exit(0);
	}

	int numTest;
	int64_t a, b, mod, expectedValue;
	int op;
	fscanf(input, "%d", &numTest);
	for (int i = 0; i < numTest; i++) {
		fscanf(input, "%lld %lld %lld %d %lld", &a, &b, &mod, &op, &expectedValue);
		printf("%lld %lld %lld %d %lld\n", a, b, mod, op, expectedValue);
		TestCase test(a, b, mod, op, expectedValue);
		test.run();
	}
	
	return 0;
}
