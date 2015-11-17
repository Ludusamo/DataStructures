#include "tree.h"
#include "cstdio"

Tree::Entry::Entry(const string& key, double val) {
	this->key = key;
	this->val = val;
}

Tree::Entry::Entry(const Entry& e) {
	this->key = e.key;	
	this->val = e.val;
}

Tree::Node::Node(const Entry& e, Node *l, Node *r, size_t n) {
	this->e = e;
	this->l = l;
	this->r = r;
	this->n = n;
}

Tree::Node::~Node() {
	
}

void Tree::Node::kill(Node *p) {
	if (!p) return;
	Tree::Node::kill(p->l);
	Tree::Node::kill(p->r);
	delete p; 
} 

Tree::It::It(Node *p, const stack<Node*>& s) {
	this->p = p;
	this->s = s;
}

Tree::It::It(const It& i) {
	this->p = i.p;
	this->s = i.s;	
}

Tree::It::~It() {
	for (int i = 0; i < s.size(); i++) s.pop();
	p = NULL;
}

double& Tree::It::operator*() const {
	printf("Dereferencing Node: %s\n", p->e.key.c_str());
	return p->e.val;
}

Tree::It Tree::It::operator++(int) {
	if (p->r) {
		s.push(p);
		p = p->r;
		while (p->l) {
			s.push(p);
			p = p->l;
		}
	} else if (!s.empty()) {
		while (s.top()->r == p) {
			p = s.top();
			s.pop();
		}
		p = s.top();
		s.pop();
	} else {
		return It(0, stack<Node*>());
	}
	return *this;
}

Tree::It& Tree::It::operator++() {
	(*this)++;
	return *this;
}

Tree::It Tree::It::operator--(int) {
	if (p->l) {
		s.push(p);
		p = p->l;
		while (p->r) {
			s.push(p);
			p = p->r;
		}
	} else if (!s.empty()) {
		while (s.top()->l == p) {
			p = s.top();
			s.pop();
		}
		p = s.top();
		s.pop();
	} else {
		return It(0, stack<Node*>());
	}
	return *this;
}

Tree::It& Tree::It::operator--() {
	(*this)--;
	return *this;
}

Tree::It Tree::It::operator+(long j) const {
	It it = *this;
	for (long i = 0; i < j; i++) {
		it++;
	}
	return it;
}

bool Tree::It::operator!=(const It& it) const {
	return p->e.key != it.p->e.key;
}

bool Tree::It::operator==(const It& it) const {
	return !(*this != it);
}

Tree::Tree() {
	root = new Node(Entry("Brendan", 2));
	root->l = new Node(Entry("BA", 1));
	root->l->l = new Node(Entry("AJ", 3));
}

Tree::~Tree() {
	Node::kill(root);
}

size_t Tree::size() const {
	return root->n;
}

bool Tree::empty() const {
	return !root;
}

Tree::It Tree::get(const string& key) const {
	It it = hi();
	while (it.p && it.p->e.key != key) {		
		*it;	
		it--;	
	}
	return it;
}

bool Tree::set(const string& key, double val) {
	It it = lo();
	while (it != hi() && it.p->e.key < key) {
		it++;
	}
	if (it.p->e.key == key) {
		it.p->e.val = val;
		return true;
	} else if (it == hi()) {
		Node *newNode = new Node(Entry(key, val));	
		it.p->r = newNode;
		return true;
	}

	Node *newNode = new Node(Entry(key, val), it.p->l, it.p, it.p->n + it.p->n + 1);
	it.p->l = 0;
	Node *parent = it.s.top();
	if (parent->l == it.p) parent->l = newNode;
	else if (parent->r == it.p) parent->r = newNode;
	return false;
}

Tree::It Tree::lo() const {
	Node *buffer = root;
	stack<Node*> s = stack<Node*>();
	while (buffer->l) {
		s.push(buffer);
		buffer = buffer->l;
	}
	return It(buffer, s);
}

Tree::It Tree::hi() const {
	Node *buffer = root;
	stack<Node*> s = stack<Node*>();
	while (buffer->r) {
		s.push(buffer);
		buffer = buffer->r;
	}
	return It(buffer, s);
}

Tree::It Tree::none() const {
	return It(0, stack<Node*>());
}
