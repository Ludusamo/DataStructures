#include <stdio.h>
#include "Mod.h"

int main() {
	Mod mod1(1), mod2(2);
	mod1 = mod2;
	printf("%ld %ld\n", mod1.getX(), mod2.getX());
	return 0;
}
