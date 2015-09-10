#include "Mod.h"

Mod::Mod(long t) {
	this->x = t;
}

Mod::Mod(const Mod& m) {
	this->x = m.x;
}

Mod& Mod::operator=(const Mod& m) {

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

static void set_modulus(long m) {

}
