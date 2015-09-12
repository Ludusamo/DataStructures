#include <stdio.h>
#include <climits>
#include "Mod.h"

int main() {
	printf("%i\n", sizeof(long));
	Mod::set_modulus((LLONG_MAX) - 1);
	Mod mod1(LLONG_MAX - 2), mod2(LLONG_MAX - 2);
	Mod AddMod = mod1 + mod2;
	return 0;
}
