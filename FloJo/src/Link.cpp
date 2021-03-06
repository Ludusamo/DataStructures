#include "Link.h"

std::vector<int32_t> josephus(int32_t n, int32_t k) {
	if (n == 0) return std::vector<int32_t>();
	if (k == 0) {
		printf("Cannot set k < 1\n");
		exit(-1);
	}
	// Creates circularly linked list in reverse order
	Link<int32_t> *beginning = new Link<int32_t>(n);
	Link<int32_t> *nextLink = beginning;
	for (int32_t i = n - 1; i > 0; i--) {
		Link<int32_t> *link = new Link<int32_t>(i, nextLink);
		nextLink = link;
	}
	beginning->next = nextLink;

	Link<int32_t> *currentLink = beginning;
	std::vector<int32_t> deathOrder;
	int32_t counter = 0;
	while (currentLink->next != currentLink) {
		counter++;
		if (counter == k) {
			nextLink = currentLink->next;
			currentLink->next = nextLink->next;	
			deathOrder.push_back(nextLink->info);
			counter = 0;
			nextLink->next = 0;
			delete nextLink;
		} else currentLink = currentLink->next;
	}
	deathOrder.push_back(currentLink->info);

	return deathOrder;
}
