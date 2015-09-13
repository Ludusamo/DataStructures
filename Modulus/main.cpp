#include <stdio.h>
#include <climits>
#include "Mod.h"
#include "ExtendedEuclidean.h"

int64_t mod = 7;
int64_t a = 2;
int64_t b = 3;


void resetVariables(Mod& mod1, Mod& mod2) {
	mod1 = Mod(a);
	mod2 = Mod(b);
}

int main() {	
	Mod::set_modulus(mod);
	Mod mod1(a), mod2(b);
	printf("Mod: %lld, A: %lld, B: %lld\n", mod, a, b);
	printf("MAX SIZE = %lld\n", LLONG_MAX);

	printf("--------------\n");
	resetVariables(mod1, mod2);
	printf("Addition\n");	
	mod1 + mod2;

	printf("--------------\n");
	resetVariables(mod1, mod2);
	printf("Subtraction\n");	
	mod1 - mod2;

	printf("--------------\n");
	resetVariables(mod1, mod2);
	printf("Multiplication\n");	
	mod1 * mod2;

	printf("--------------\n");
	resetVariables(mod1, mod2);
	printf("Power\n");	
	mod1.pwr(b);

	printf("--------------\n");
	resetVariables(mod1, mod2);
	printf("Division\n");	
	mod1 / mod2;
	
	return 0;
}
