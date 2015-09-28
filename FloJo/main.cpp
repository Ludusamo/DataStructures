#include <cstdio>
#include <climits>
#include <stdlib.h>
#include <time.h>

#include "Link.h"

typedef Link<int32_t> ILink;

int main() {
	printf("Floyd:\n");
	int32_t CHAIN_LENGTH = 10;
	int32_t LOOP_LINK = 10;


	ILink *ending = new ILink(CHAIN_LENGTH);
	ILink *next = ending;
	if (CHAIN_LENGTH = LOOP_LINK) ending->next = ending;
	for (int32_t i = CHAIN_LENGTH - 1; i > 0; i--) {
		ILink *link = new ILink(i, next);
		next = link;
		if (i == LOOP_LINK) ending->next = link;
	}
	ILink *beginning = next;

	std::vector<int32_t> loopTailInfo = loopTail(beginning);
	printf("<%i, %i>\n", loopTailInfo[0], loopTailInfo[1]);

	ending->next = 0;
	delete beginning;

	printf("\nJosephus:\n");
	int32_t n = 10; 
	int32_t k = 3; 

	std::vector<int32_t> deathOrder = josephus(n, k);
	
	printf("Death Order:\n");
	for (int32_t i = 0; i < deathOrder.size(); i++) {
		printf("%i ", deathOrder[i]);
	}
	printf("\n");
}
