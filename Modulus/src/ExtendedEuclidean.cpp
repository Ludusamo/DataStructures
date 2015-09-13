#include <ExtendedEuclidean.h>

ExtendedEuclidean::ExtendedEuclidean(int64_t a, int64_t b) {
	this->a = a;
	this->b = b;
	sPrev = 1;
	sCurr = 0;
	tPrev = 0;
	tCurr = 1;
}

void ExtendedEuclidean::execute() {	
	while (b % (a % b) != 0) {
		int64_t bufferS = calculateNextST(sPrev, sCurr, a / b);
		sPrev = sCurr;
		sCurr = bufferS;

		int64_t bufferT = calculateNextST(tPrev, tCurr, a / b);
		tPrev = tCurr;
		tCurr = bufferT;

		int64_t buffer = a;
		a = b;
		b = buffer % b;	
	}
	int64_t bufferS = calculateNextST(sPrev, sCurr, a / b);
	sPrev = sCurr;
	sCurr = bufferS;

	int64_t bufferT = calculateNextST(tPrev, tCurr, a / b);
	tPrev = tCurr;
	tCurr = bufferT;
	gcd = a % b;
	printf("GCD: %lld\nSCurr: %lld\nTCurr: %lld\n", gcd, sCurr, tCurr);
}

BezoutIdentity ExtendedEuclidean::getBezoutIdentity() {
	BezoutIdentity i = {a, b, sCurr, tCurr, gcd};
	return i;
}

int64_t ExtendedEuclidean::calculateNextST(int64_t prev, int64_t curr, int64_t q) {
	return prev - q * curr;
}
