#ifndef LINK_H
#define LINK_H

#include <vector>
#include <cstdio>
#include <stdint.h>

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

Link<int32_t> *hasLoop(Link<int32_t>* head); // Returns a link in the loop
int32_t determineLoopSize(Link<int32_t>* linkInLoop);
int32_t determineTailSize(Link<int32_t>* head, int32_t loopSize);
std::vector<int32_t> loopTail(Link<int32_t>* head);
std::vector<int32_t> josephus(int32_t n, int32_t k);

#endif // LINK_H
