#include "tree.h"

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

void Tree::Node::kill(Node *p) {
	if (!p) return;
	Tree::Node::kill(p->l);
	Tree::Node::kill(p->r);
	kill(p);
}

Tree::Tree() {
	root = new Node();
}

Tree::~Tree() {
	Node::kill(root);
}
