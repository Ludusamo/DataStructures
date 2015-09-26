#include <cstdio>
#include "Link.h"

#define CHAIN_LENGTH 1000000
#define LOOP_LINK 9999

typedef Link<int32_t> ILink;

int main() {
	ILink *ending = new ILink(CHAIN_LENGTH);
	ILink *next = ending;
	for (int i = CHAIN_LENGTH - 1; i > 0; i--) {
		ILink *link = new ILink(i, next);
		next = link;
		if (i == LOOP_LINK) ending->next = link;
	}
	ILink *beginning = next;

	std::vector<int32_t> loopTailInfo = loopTail(beginning);
	printf("<%i, %i>", loopTailInfo[0], loopTailInfo[1]);
}
