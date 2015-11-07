//
//  tree.h
//  
//
//  Binary Tree Programming Assignment
//  Due: November 17, 2015 at 4:10 PM
//
//  Implement the data types specified below.
//

#ifndef _tree_h
#define _tree_h

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using std::string;
using std::vector;
using std::stack;
using std::cin;
using std::cout;
using std::cerr;

class Tree {
    
    struct Entry {
        Entry(const string& key = "", double val = 0.0);
        Entry(const Entry& e);
        
        string key;
        double val;
    };
    
    struct Node {
        Node(const Entry& e = Entry(), Node *l = 0, Node *r = 0, size_t n = 1);
        ~Node();
        
        Entry e;    // Application-specific information
        Node *l;    // Left subtree
        Node *r;    // Right subtree
        size_t n;   // # of nodes in this subtree
        
        static void kill(Node *p);  // De-allocate this subtree
    };
    
public:
    
    // The class for users to move around within the tree
    class It {
    public:
        explicit It(Node* p = 0);   // This might become private
        It(const It& i);
        ~It();
        
        double& operator*() const;
        It operator++(int);     // Post-increment
        It& operator++();       // Pre-increment
        It operator--(int);     // Post-decremenmt
        It& operator--();       // Pre-decrement
        It operator+(long j) const; // Get iterator to new location
        
    private:
        Node *p;                // Iterator refers to this location in tree
        stack<Node*> s;         // Need a stack because NO PARENT POINTERS
    };
    
    Tree();
    ~Tree();
    
    size_t size() const;                        // # of nodes in tree
    bool empty() const;                         // Is the tree empty?
    bool set(const string& key, double val);    // Set val, possibly adding node
    bool has(const string& key) const;          // Does the tree contain key?
    double get(const string& key) const;        // Get the val having this key
    bool del(const string& key);                // Remove the node having this key
    It lo() const;                              // Iterator to smallest node
    It hi() const;                              // Iterator to largest node
    It none() const;                            // Sentry iterator (for loops)
    
private:
    Node *root;
};

#endif
