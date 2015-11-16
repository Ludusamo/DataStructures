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

Tree::It Tree::It::operator++(int) {
	p = s.top();	s.pop();
}

Tree::It& Tree::It::operator++() {

}

Tree::Tree() {
	root = new Node();
}

Tree::~Tree() {
	Node::kill(root);
}

size_t Tree::size() const {
	return root->n;
}

bool Tree::empty() const {
	return root;
}

bool Tree::set(const string& key, double val) {
	Node *currentNode;
	vector<Node*> unvisitedNodes = vector<Node*>();
	unvisitedNodes.push_back(root);
	while (unvisitedNodes.size() > 0) {
		currentNode = unvisitedNodes[unvisitedNodes.size() - 1];
		if (currentNode->e.key == key) {
			currentNode->e.val = val;
			return true;
		}
		unvisitedNodes.pop_back();
		if (currentNode->l) unvisitedNodes.push_back(currentNode->l);
		if (currentNode->r) unvisitedNodes.push_back(currentNode->r);
	}
	return false;
}
