#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cstdio>

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

std::vector<int> loopTail(Link<int>* head);
std::vector<int> josephus(int n, int k);

#endif // VECTOR_H
