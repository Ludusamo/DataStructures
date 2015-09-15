#ifndef TESTCASE_H
#define TESTCASE_H

#include "Mod.h"
#include <stdio.h>
#include <sys/time.h>

class TestCase {
public:
	TestCase(int64_t a, int64_t b, int64_t mod, int op, int64_t expectedValue);
	TestCase(const TestCase& t);

	int run();
private:
	typedef enum {
		ADD,
		SUB,
		MUL,
		DIV,
		POW,
		EQ,
		NEQ
	} OPERATION;
	int op;
	int64_t a, b, mod;
	int64_t expectedValue;	
};
	
#endif // TESTCASE_H
