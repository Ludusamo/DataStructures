#include "Link.h"

Link<int32_t> *hasLoop(Link<int32_t>* head) {
	Link<int32_t> *turtle = head;
	Link<int32_t> *hare = head;

	do {
		if (hare->next == 0 || hare->next->next == 0 || turtle->next == 0) 
			return 0;
		turtle = turtle->next;
		hare = hare->next->next;
		printf("(Turtle, Hare):(%i,%i)\n", turtle->info, hare->info);
	} while (turtle->info != hare->info);
	return hare;
}

int32_t determineLoopSize(Link<int32_t>* linkInLoop) {
	Link<int32_t> *counter = linkInLoop->next;
	int32_t count = 1;
	while (counter->info != linkInLoop->info) {
		count++;
		counter = counter->next;
	}
	return count;
}

std::vector<int32_t> loopTail(Link<int32_t>* head) {	
	Link<int32_t> *loopLink = hasLoop(head);
	if (loopLink != 0) {
		int32_t loopSize = determineLoopSize(loopLink);
		printf("Loop Size: %i\n", loopSize);
	}
}

std::vector<int> josephus(int n, int k) {

}
