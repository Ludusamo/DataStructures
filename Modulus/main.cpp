#include <stdio.h>
#include <climits>
#include "Mod.h"
#include "TestCase.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

long mod = 34;
long a = LLONG_MAX - 500;
long b = 17;


int main() {	
	Mod::set_modulus(1);
	Mod mod1(a), mod2(b);
	mod1 /= mod2;

	struct timeval prevTime, currTime, elapsedTime;

	FILE *output;
	//output = fopen("res/test2.csv", "w");

	FILE *input;
	input = fopen("res/test2.csv", "r");	
	if (input == NULL) {
		printf("File does not exist!\n");
		exit(0);
	}

	int64_t numCorrect = 0;
	int64_t mod, a, b, dum1, dum2, sum, difference, product, quotient, power;
	int64_t numTest = 96000;
	gettimeofday(&prevTime, NULL);
	for (int i = 0; i < numTest; i++) {
		fscanf(input, "%ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld", &mod, &a, &b, &dum1, &dum2, &sum, &difference, &product, &quotient, &power);
		TestCase test(a, b, mod, 0, sum);
		TestCase test1(a, b, mod, 1, difference);
		TestCase test2(a, b, mod, 2, product);
		TestCase test3(a, b, mod, 3, quotient);
		TestCase test4(a, b, mod, 4, power);
		if(test.run()) numCorrect++;
		if(test1.run()) numCorrect++;
		if(test2.run()) numCorrect++;
		if(test3.run()) numCorrect++;
		if(test4.run()) numCorrect++;

		//fprintf(output, "%ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld\n", mod, a, -b, Mod(a).val(), Mod(b).val(), (Mod(a) + Mod(-b)).val(), (Mod(a) - Mod(-b)).val(), (Mod(a) * Mod(-b)).val(), (Mod(a) / Mod(-b)).val(), Mod(a).pwr(-b).val());
	}
	gettimeofday(&currTime, NULL);
	timersub(&currTime, &prevTime, &elapsedTime);
	printf("%ld out of %ld correct\n", numCorrect, numTest * 5);
	printf("Time elapsed: %ld.%06lds\n", (long int)elapsedTime.tv_sec, (long int)elapsedTime.tv_usec);
	
	return 0;
}
