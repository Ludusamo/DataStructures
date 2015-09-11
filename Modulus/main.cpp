#include <stdio.h>
#include "Mod.h"

int main() {
	Mod mod1(1), mod2(2);
	Mod::set_modulus(5);
	printf("%ld %ld\n", mod1.getMod(), mod2.getMod());
	return 0;
}
