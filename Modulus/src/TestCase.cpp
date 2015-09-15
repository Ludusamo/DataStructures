#include "TestCase.h"
#include <unistd.h>

TestCase::TestCase(int64_t a, int64_t b, int64_t mod, int op, int64_t expectedValue) {
	this->a = a;
	this->b = b;
	this->mod = mod;	
	this->op = op;
	this->expectedValue = expectedValue;
}

TestCase::TestCase(const TestCase& t) {
	this->a = t.a;
	this->b = t.b;
	this->mod = t.mod;
	this->expectedValue = t.expectedValue;
}

int TestCase::run() {
	const char *operation;
	struct timeval prevTime, currTime, elapsedTime;
	Mod::set_modulus(mod);
	Mod mod1(a), mod2(b);

	int64_t result;
	gettimeofday(&prevTime, NULL);
	switch (op) {
	case ADD:
		operation = "+";
		result = (mod1 + mod2).val();	
		break;
	case SUB:
		operation = "-";
		result = (mod1 - mod2).val();	
		break;
	case MUL:
		operation = "*";
		result = (mod1 * mod2).val();	
		break;
	case DIV:
		operation = "/";
		result = (mod1 / mod2).val();	
		break;
	case EQ:
		operation = "==";
		result = mod1 == mod2;
		break;
	case NEQ:
		operation = "!=";
		result = mod1 != mod2;
		break;
	};
	gettimeofday(&currTime, NULL);
	timersub(&currTime, &prevTime, &elapsedTime);

	printf("---------------------------------------------------------\n");
	printf("Test case: (%lld %s %lld) %c %lld\n", a, operation, b, '%', mod);
	printf("Time elapsed: %ld.%06lds\n", (long int)elapsedTime.tv_sec, (long int)elapsedTime.tv_usec);
	printf("Result: %lld %s %lld\n", result, (result == expectedValue) ? "matches" : "does not match", expectedValue);
	printf("---------------------------------------------------------\n\n");
}
