#include <cstdio>
#include <climits>

#include "Link.h"

#define CHAIN_LENGTH 1000000
#define LOOP_LINK 9999

typedef Link<int32_t> ILink;

int main() {
	printf("Floyd:\n");
	ILink *ending = new ILink(CHAIN_LENGTH);
	ILink *next = ending;
	for (int i = CHAIN_LENGTH - 1; i > 0; i--) {
		ILink *link = new ILink(i, next);
		next = link;
		if (i == LOOP_LINK) ending->next = link;
	}
	ILink *beginning = next;

	std::vector<int32_t> loopTailInfo = loopTail(beginning);
	printf("<%i, %i>\n", loopTailInfo[0], loopTailInfo[1]);

	printf("\nJosephus:\n");
	std::vector<int32_t> deathOrder = josephus(100, 3);
	
	printf("Death Order:\n");
	for (int32_t i = 0; i < deathOrder.size(); i++) {
		printf("%i\n", deathOrder[i]);
	}
}
