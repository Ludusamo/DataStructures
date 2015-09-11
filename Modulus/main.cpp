#include <stdio.h>
#include <inttypes.h>
#include "Mod.h"

int main() {
	Mod mod1(2147483645), mod2(2147483645);
	Mod::set_modulus(2147483647);
	mod1 += mod2;
	printf("%d %d", INT32_MIN, INT32_MAX);
	return 0;
}
