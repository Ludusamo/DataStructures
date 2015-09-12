#include <stdio.h>
#include <climits>
#include "Mod.h"

int64_t mod = LLONG_MAX;
int64_t a = LLONG_MAX - 1;
int64_t b = LLONG_MAX - 1;

int main() {
	Mod::set_modulus(mod);
	Mod mod1(a), mod2(b);
	printf("MAX SIZE = %lld\n", LLONG_MAX);
	printf("--------------\n");
	printf("Addition\n");	
	mod1 += mod2;
	printf("--------------\n");
	printf("Subtraction\n");	
	mod1 -= mod2;
	printf("--------------\n");
	printf("Multiplication\n");	
	mod1 *= mod2;
	return 0;
}
