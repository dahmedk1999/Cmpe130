// Red Black Tree implementation in C++
// Author: Algorithm Tutor
// Tutorial URL: https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/

#include <iostream>

using namespace std;

// data structure that represents a node in the tree
struct rbNode {
    int data; // holds the key
    rbNode *parent; // pointer to the parent
    rbNode *left; // pointer to left child
    rbNode *right; // pointer to right child
    int color; // 1 -> Red, 0 -> Black
};

typedef rbNode *ptrnode;

class RBTree {
private:
    ptrnode root;
    ptrnode TNULL;

    void initializeNULLNode(ptrnode node, ptrnode parent) {
        node->data = 0;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = 0;
    }

    void preOrderHelper(ptrnode node) {
        if (node != TNULL) {
            cout<<node->data;
            if(node->color==0)cout<<"*";
            cout<<" ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    // fix the red-black tree
    void fixInsert(ptrnode k){
        ptrnode u;
        while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left; // uncle
                if (u->color == 1) {
                    // case 3.1
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        // case 3.2.2
                        k = k->parent;
                        rightRotate(k);
                    }
                    // case 3.2.1
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right; // uncle

                if (u->color == 1) {
                    // mirror case 3.1
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        // mirror case 3.2.2
                        k = k->parent;
                        leftRotate(k);
                    }
                    // mirror case 3.2.1
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = 0;
    }

public:
    RBTree() {
        TNULL = new rbNode;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    void preorder() {
        preOrderHelper(this->root);
    }

    // rotate left at node x
    void leftRotate(ptrnode x) {
        ptrnode y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // rotate right at node x
    void rightRotate(ptrnode x) {
        ptrnode y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insert(int key) {
        // Ordinary Binary Search Insertion
        ptrnode node = new rbNode;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1; // new node must be red

        ptrnode y = nullptr;
        ptrnode x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        // y is parent of x
        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        // if new node is a root node, simply return
        if (node->parent == nullptr){
            node->color = 0;
            return;
        }

        // if the grandparent is null, simply return
        if (node->parent->parent == nullptr) {
            return;
        }

        // Fix the tree
        fixInsert(node);
    }

    ptrnode getRoot(){
        return this->root;
    }

};
