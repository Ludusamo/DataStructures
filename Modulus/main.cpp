#include <stdio.h>
#include "Mod.h"

int main() {
	Mod mod1(6), mod2(7);
	Mod::set_modulus(5);
	printf("%ld %ld\n", mod1.val(), mod2.val());
	return 0;
}
