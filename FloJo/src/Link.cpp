#include "Link.h"

std::vector<int> loopTail(Link<int>* head) {

}

std::vector<int> josephus(int n, int k) {
	// Creates circularly linked list in reverse order
	Link<int> *beginning = new Link<int>(n);
	Link<int> *nextLink = beginning;
	for (int i = n - 1; i > 0; i--) {
		Link<int> *link = new Link<int>(i, nextLink);
		nextLink = link;
	}
	beginning->next = nextLink;

	Link<int> *currentLink = beginning;
	std::vector<int> deathOrder;
	int counter = 0;
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

	delete beginning;
	return deathOrder;
}
