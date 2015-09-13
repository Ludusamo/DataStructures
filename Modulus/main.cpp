#include <stdio.h>
#include <climits>
#include "Mod.h"
#include "ExtendedEuclidean.h"

int64_t mod = LLONG_MAX;
int64_t a = LLONG_MAX - 43;
int64_t b = LLONG_MAX - 53;


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
	ExtendedEuclidean e(5, ;
	e.execute();

	return 0;
}
