#include "Mod.h"
#include <inttypes.h>

#define MAX_LONG_SIZE 2147483647
#define MIN_LONG_SIZE -2147483648
long Mod::modulus;

Mod::Mod(long t) {
	this->x = t;
}

Mod::Mod(const Mod& m) {
	this->x = m.x;
}

Mod& Mod::operator=(const Mod& m) {
	x = m.x;
	return *this;
}

#include<stdio.h>

Mod operator+(const Mod& a, const Mod& b) {
	
}

Mod& Mod::operator+=(const Mod& m) {
	long mod1 = this->val();
	long mod2 = m.val();
	long sum = mod1 + mod2;
	printf("%ld %ld %ld\n", mod1, mod2, sum);
	if (sum < 0) {
		mod1 -= (MAX_LONG_SIZE - mod2);
		printf("%ld\n", mod1);
		long r = ((MAX_LONG_SIZE % modulus) + (mod1 % modulus)) % modulus;
		printf("%ld\n", r);
	}
}

Mod& Mod::operator-=(const Mod& m) {

}

Mod& Mod::operator*=(const Mod& m) {

}

Mod& Mod::operator/=(const Mod& m) {

}

Mod Mod::operator-() const {

}

Mod Mod::pwr(long e) const {

}

long Mod::val() const {
	return x % modulus;
}

void Mod::set_modulus(long m) {
	Mod::modulus = m;
}
