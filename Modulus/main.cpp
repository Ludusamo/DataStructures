#include <stdio.h>
#include <climits>
#include "Mod.h"

int main() {
	Mod::set_modulus(9223372036854775807);
	Mod mod1(-9223372036854775804), mod2(-9223372036854775805);
	Mod AddMod = mod1 - mod2;
	return 0;
}
