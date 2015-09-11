#include "Mod.h"
#include <climits>

long Mod::modulus;

Mod::Mod(long t) {
	this->x = t % modulus;
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
	Mod mod1 = a;
	Mod mod2 = b;
	mod1 += mod2;
	return Mod(mod1.val());
}

Mod& Mod::operator+=(const Mod& m) {
	long mod1 = this->val();
	long mod2 = m.val();
	long sum = mod1 + mod2;
	printf("%ld %ld %ld\n", mod1, mod2, sum);
	if ((mod1 / 2) + (mod2 / 2) >= (LLONG_MAX / 2)) {
		mod1 -= (LLONG_MAX - mod2);
		printf("%ld\n", mod1);
		long r = ((LLONG_MAX % modulus) + (mod1 % modulus)) % modulus;
		printf("%ld\n", r);
		x = r;
	} else if ((mod1 / 2) + (mod2 / 2) <= (LLONG_MIN / 2)) {
		mod1 = mod1 - (LLONG_MIN - mod1);
		printf("%ld\n", mod1);
		long r = ((LLONG_MIN % modulus) + (mod1 % modulus))  % modulus;
		printf("%ld\n", r);
		x = r;
	} else {
		x = sum;
		printf("%ld\n", x);
	}
	return *this;
}

Mod operator-(const Mod& a, const Mod& b) {
	Mod mod1 = a;
	Mod mod2 = b;
	mod1 -= mod2;
	return Mod(mod1.val());
}

Mod& Mod::operator-=(const Mod& m) {
	Mod mod1(this->val());	
	Mod mod2(-m.val());
	mod1 += mod2;
	x = mod1.val();
	return *this;
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
	return x;
}

void Mod::set_modulus(long m) {
	Mod::modulus = m;
}
