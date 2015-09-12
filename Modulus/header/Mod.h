/*
    Assignment: Implement the following class. Make sure that it handles all signed 8-byte integers correctly and without overflow.
 
    For now, if the user attempts to divide by zero or set the modulus to something < 2, you can just "fail fast" with exit(-1).
 
    DUE: September 22, 2014 (by midnight!)
*/

#ifndef ____Mod__
#define ____Mod__

#include <iostream>
#include <cassert>
#include <stdint.h>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::cerr;

class Mod {
public:
    Mod(int64_t t);
    Mod(const Mod& m);
    Mod& operator=(const Mod& m);
    Mod& operator+=(const Mod& m);
    Mod& operator-=(const Mod& m);
    Mod& operator*=(const Mod& m);
    Mod& operator/=(const Mod& m);
    Mod operator-() const;
    Mod pwr(int64_t e) const;
    int64_t val() const;
    
    static void set_modulus(int64_t m); 
private:
    int64_t x;
    static int64_t modulus;
    
    static Mod inv(int64_t r0);
};


Mod operator+(const Mod& a, const Mod& b);
Mod operator+(int64_t t, const Mod& m);
Mod operator-(const Mod& a, const Mod& b);
Mod operator-(int64_t t, const Mod& m);
Mod operator*(const Mod& a, const Mod& b);
Mod operator*(int64_t t, const Mod& m);
Mod operator/(const Mod& a, const Mod& b);
Mod operator/(int64_t t, const Mod& m);
bool operator==(const Mod& a, const Mod& b);
bool operator==(int64_t t, const Mod& m);
bool operator!=(const Mod& a, const Mod& b);
bool operator!=(int64_t t, const Mod& m);

istream& operator>>(istream& is, Mod& m);
ostream& operator<<(ostream& os, const Mod& m);

#endif /* defined(____Mod__) */
