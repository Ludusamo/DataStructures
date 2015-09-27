#include <cstdio>
#include <climits>
#include <stdlib.h>
#include <time.h>

#include "Link.h"

typedef Link<int32_t> ILink;

int main() {
	FILE *floydTestCases, *josephusTestCases;
	floydTestCases = fopen("res/floyd.in", "w");
	josephusTestCases = fopen("res/josephus.in", "w");

	printf("Floyd:\n");
	for (int x = 0; x <= 1000; x++) {
		srand(time(NULL));
		int32_t CHAIN_LENGTH = rand() % (1000 * (x + 1)); 
		srand(time(NULL));
		CHAIN_LENGTH += rand() % 1000;
		srand(time(NULL));
		int32_t LOOP_LINK = (rand() % CHAIN_LENGTH) - 1;


		//printf("%i %i\n", CHAIN_LENGTH, LOOP_LINK);
		ILink *ending = new ILink(CHAIN_LENGTH);
		ILink *next = ending;
		for (int32_t i = CHAIN_LENGTH - 1; i > 0; i--) {
			ILink *link = new ILink(i, next);
			next = link;
			if (i == LOOP_LINK) ending->next = link;
		}
		ILink *beginning = next;

		std::vector<int32_t> loopTailInfo = loopTail(beginning);
		//printf("<%i, %i>\n", loopTailInfo[0], loopTailInfo[1]);
		fprintf(floydTestCases, "%i %i %i %i\n", CHAIN_LENGTH, LOOP_LINK, loopTailInfo[0], loopTailInfo[1]);
		ending->next = 0;
		delete beginning;
	}

	printf("\nJosephus:\n");
	for (int i = 0; i < 99; i++) {
		srand(time(NULL));
		int32_t n = rand() % (10000 * (i + 1)); 
		srand(time(NULL));
		int32_t k = rand() % 1000; 

		std::vector<int32_t> deathOrder = josephus(n, k);
		
		fprintf(josephusTestCases, "%i %i ", n, k);
		for (int32_t i = 0; i < deathOrder.size(); i++) {
			fprintf(josephusTestCases, "%i ", deathOrder[i]);
		}
		fprintf(josephusTestCases, "\n");
	}
	std::vector<int32_t> deathOrder = josephus(1000000, 17);
		
	fprintf(josephusTestCases, "%i %i ", 1000000, 17);
	printf("Death Order:\n");
	for (int32_t i = 0; i < deathOrder.size(); i++) {
		fprintf(josephusTestCases, "%i ", deathOrder[i]);
		printf("%i\n", deathOrder[i]);
	}
	fprintf(josephusTestCases, "\n");
}
