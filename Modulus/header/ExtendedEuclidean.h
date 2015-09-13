#ifndef EXTENDEDEUCLIDEAN_H
#define EXTENDEDEUCLIDEAN_H

#include <stdio.h>
#include <cassert>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
	int64_t a, b, x, y, gcd;
} BezoutIdentity;

class ExtendedEuclidean {
public:
	ExtendedEuclidean(int64_t a, int64_t b);
	
	void execute();
	BezoutIdentity getBezoutIdentity();	 
private:
	int64_t a, b, sPrev, sCurr, tPrev, tCurr;	
	int64_t gcd;

	int64_t calculateNextST(int64_t prev, int64_t curr, int64_t q);
};

#endif // EXTENDEDEUCLIDEAN_H
