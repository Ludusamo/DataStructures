#include "Link.h"

Link<int32_t> *hasLoop(Link<int32_t>* head) {
	Link<int32_t> *turtle = head;
	Link<int32_t> *hare = head;

	do {
		if (hare->next == 0 || hare->next->next == 0 || turtle->next == 0) 
			return 0;
		turtle = turtle->next;
		hare = hare->next->next;
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

int32_t determineTailSize(Link<int32_t>* head, int32_t loopSize) {
	Link<int32_t> *link1 = head;
	Link<int32_t> *link2 = head;
	for (int32_t i = 0; i < loopSize; i++)
		link2 = link2->next;

	int32_t counter = 0;
	while (link1 != link2) {
		counter++;
		link1 = link1->next;
		link2 = link2->next;
	}
	return counter;
}

std::vector<int32_t> loopTail(Link<int32_t>* head) {	
	Link<int32_t> *loopLink = hasLoop(head);
	std::vector<int32_t> loopTailInfo(2);
	if (loopLink != 0) {
		int32_t loopSize = determineLoopSize(loopLink);
		loopTailInfo[0] = loopSize;
		int32_t tailSize = determineTailSize(head, loopSize);
		loopTailInfo[1] = tailSize;
	}
	return loopTailInfo;
}

std::vector<int> josephus(int n, int k) {

}
