#include "Mod.h"

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

Mod& Mod::operator+=(const Mod& m) {

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

}

void Mod::set_modulus(long m) {
	Mod::modulus = m;
}
