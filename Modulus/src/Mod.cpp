#include "Mod.h"
#include "ExtendedEuclidean.h"
#include <climits>
#include <stdlib.h>
#include <stdio.h>

int64_t Mod::modulus;

Mod::Mod(int64_t t) {
	this->x = t % modulus;
}

Mod::Mod(const Mod& m) {
	this->x = m.val();
}

Mod& Mod::operator=(const Mod& m) {
	x = m.val();
	return *this;
}

Mod& Mod::operator+=(const Mod& m) {
	int64_t mod1 = this->val();
	int64_t mod2 = m.val();
	int64_t sum = mod1 + mod2;
	if ((mod1 / 2) + (mod2 / 2) >= (LLONG_MAX / 2)) {
		mod1 -= (LLONG_MAX - mod2);
		int64_t r = ((LLONG_MAX % modulus) + (mod1 % modulus)) % modulus;
		x = r;
	} else if ((mod1 / 2) + (mod2 / 2) <= (LLONG_MIN / 2)) {
		mod1 = mod1 - (LLONG_MIN - mod1);
		int64_t r = ((LLONG_MIN % modulus) + (mod1 % modulus))  % modulus;
		x = r;
	} else {
		x = sum % modulus;
	}
	if (x < 0) x = modulus + x;
	return *this;
}

Mod& Mod::operator-=(const Mod& m) {
	Mod mod2 = -m;
	*this += mod2;
	return *this;
}

Mod& Mod::operator*=(const Mod& m) {
	long double xBuffer = this->val(); // To prevent loss from divison
	int64_t pMQ = xBuffer * m.val() / modulus; // Quotient of Product and Modulus
	int64_t r = ((this->val() * m.val()) - (pMQ * modulus)) % modulus;
	x = (r < 0) ? r + modulus : r;
	return *this;
}

Mod& Mod::operator/=(const Mod& m) {
	Mod inverse = inv(m.val());
	*this *= inverse;
	return *this;
}

Mod Mod::operator-() const {
	return Mod(-this->x);
}

Mod power(const Mod& m, int64_t e) {
	if (e == 1) return m;
	bool isEven = (e % 2 == 0);
	Mod square = m * m;
	if (isEven) {
		return power(square, e / 2);
	} else {
		return m * power(square, e / 2);
	}
}

Mod Mod::pwr(int64_t e) const {
	Mod p = *this;
	if (e < 0) {
		Mod inverse = inv(x);
		p = power(inverse, e * -1);
	} else p = power(*this, e);
	return p;
}

int64_t calculateNextS(int64_t prev, int64_t curr, int64_t q) {
	return prev - q * curr;
}

int64_t extendedEuclidean(int64_t a, int64_t b) {
	int64_t sPrev = 1;
	int64_t sCurr = 0;
	int64_t tPrev = 0;
	int64_t rCurr = 1;
	if (a % b == 0) {
		printf("Cannot divide by 0\n");
		exit(0);
	}
	while (b % (a % b) != 0) {
		int64_t bufferS = calculateNextS(sPrev, sCurr, a / b);
		sPrev = sCurr;
		sCurr = bufferS;

		int64_t buffer = a;
		a = b;
		b = buffer % b;	
	}
	int64_t bufferS = calculateNextS(sPrev, sCurr, a / b);
	sPrev = sCurr;
	sCurr = bufferS;

	return sCurr;
}

Mod Mod::inv(int64_t r0) {
	return Mod(extendedEuclidean(r0, modulus));
}

int64_t Mod::val() const {
	return x;
}

Mod operator+(const Mod& a, const Mod& b) {
	Mod mod1 = a;
	Mod mod2 = b;
	mod1 += mod2;
	return Mod(mod1.val());
}

Mod operator+(int64_t t, const Mod& m) {
	return Mod(t) + m;
}

Mod operator-(const Mod& a, const Mod& b) {
	Mod mod1 = a;
	Mod mod2 = b;
	mod1 -= mod2;
	return Mod(mod1.val());
}

Mod operator-(int64_t t, const Mod& m) {
	return Mod(t) - m;
}

Mod operator*(const Mod& a, const Mod& b) {
	Mod mod1 = a;
	Mod mod2 = b;
	mod1 *= mod2;
	return Mod(mod1.val());
}

Mod operator*(int64_t t, const Mod& m) {
	return Mod(t) * m;
}

Mod operator/(const Mod& a, const Mod& b) {
	Mod mod1 = a;
	Mod mod2 = b;
	mod1 /= mod2;	
	return Mod(mod1.val());
}

Mod operator/(int64_t t, const Mod& m) {
	return Mod(t) / m;
}

bool operator==(const Mod& a, const Mod& b) {
	return a.val() == b.val();
}

bool operator==(int64_t t, const Mod& b) {
	return Mod(t) == b;
}

bool operator!=(const Mod& a, const Mod& b) {
	return a.val() != b.val();
}

bool operator!=(int64_t t, const Mod& b) {
	return Mod(t) != b;
}

istream& operator>>(istream& is, Mod& m) {
	int64_t t;
	is >> t;
	m = Mod(t);
	return is;
}

ostream& operator<<(ostream& os, const Mod& m) {
	os << m.val();
	return os;
}

void Mod::set_modulus(int64_t m) {
	if (m < 2) {
		exit(-1);
	}
	Mod::modulus = m;
}
