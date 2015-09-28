#ifndef LINK_H
#define LINK_H

#include <vector>
#include <cstdio>
#include <stdint.h>
#include <stdlib.h>

template<class T>
struct Link {
	explicit Link(const T& info, Link *next = 0) : info(info), next(next) { }
	// This avoids stack overflow
	~Link() {
		Link *p = next;
		while (p) {
			Link *q = p->next;
			p->next = 0;
			delete p;
			p = q;
		}
	}
	T info;
	Link *next;
};

template<class T>
Link<T> *hasLoop(Link<T>* head) {
	Link<T> *turtle = head;
	Link<T> *hare = head;
	do {
		if (hare->next == 0 || hare->next->next == 0 || turtle->next == 0) 
			return 0;
		turtle = turtle->next;
		hare = hare->next->next;
	} while (turtle != hare);
	return hare;
}

template<class T>
int32_t determineLoopSize(Link<T>* linkInLoop) {
	Link<T> *counter = linkInLoop->next;
	int32_t count = 1;
	while (counter != linkInLoop) {
		count++;
		counter = counter->next;
	}
	return count;
}

template<class T>
int32_t determineTailSize(Link<T>* head, int32_t loopSize) {
	Link<T> *link1 = head;
	Link<T> *link2 = head;
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

template<class T>
std::vector<int32_t> loopTail(Link<T>* head) {
	std::vector<int32_t> loopTailInfo(2);
	if (head == 0) return loopTailInfo;
	Link<T> *loopLink = hasLoop(head);
	if (loopLink != 0) {
		int32_t loopSize = determineLoopSize(loopLink);
		loopTailInfo[0] = loopSize;
		int32_t tailSize = determineTailSize(head, loopSize);
		loopTailInfo[1] = tailSize;
	} else {
		int32_t tailSize = 0;
		Link<T> *link = head;
		while (link != 0) {
			tailSize++;
			link = link->next;	
		}
		loopTailInfo[1] = tailSize;
	}
	return loopTailInfo;
}

std::vector<int32_t> josephus(int32_t n, int32_t k);

#endif // LINK_H
