#include "Mod.h"
#include <climits>

int64_t Mod::modulus;

Mod::Mod(int64_t t) {
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
	int64_t mod1 = this->val();
	int64_t mod2 = m.val();
	int64_t sum = mod1 + mod2;
	printf("%lld %lld %lld\n", mod1, mod2, sum);
	if ((mod1 / 2) + (mod2 / 2) >= (LLONG_MAX / 2)) {
		mod1 -= (LLONG_MAX - mod2);
		printf("%lld\n", mod1);
		int64_t r = ((LLONG_MAX % modulus) + (mod1 % modulus)) % modulus;
		printf("Remainder: %lld\n", r);
		x = r;
	} else if ((mod1 / 2) + (mod2 / 2) <= (LLONG_MIN / 2)) {
		mod1 = mod1 - (LLONG_MIN - mod1);
		printf("%lld\n", mod1);
		int64_t r = ((LLONG_MIN % modulus) + (mod1 % modulus))  % modulus;
		printf("Remainder: %lld\n", r);
		x = r;
	} else {
		x = sum;
		printf("Remainder: %lld\n", x);
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
	Mod mod2 = -m;
	*this += mod2;
	return *this;
}

Mod& Mod::operator*=(const Mod& m) {
	
}

Mod& Mod::operator/=(const Mod& m) {

}

Mod Mod::operator-() const {
	return Mod(-this->x);
}

Mod Mod::pwr(int64_t e) const {

}

int64_t Mod::val() const {
	return x;
}

void Mod::set_modulus(int64_t m) {
	Mod::modulus = m;
}
