//
// Created by Danish Khan on 9/29/2020.
//

#ifndef CMPE130_TREE_H
#define CMPE130_TREE_H

#include <iostream>
#include <vector>

class node{
public:
    node *left, *right;
    int data;
    unsigned frequency;

    explicit node(int input_data) : data(input_data), frequency(1), left(nullptr), right(nullptr) {}
    explicit node(node* copy_node){
        data = copy_node->data;
        frequency = copy_node->frequency;
        left = nullptr;
        right = nullptr;
    }
};

    class tree {
        node *root;
        int tree_size;
        double cost;
    public:
        tree();
        tree(const tree& copy);
        ~tree();

        void insert(int value);
        bool remove(int key);
        bool in_tree(int key);
        int get_frequency(int key);

        std::string to_string();
        int level(int key);
        void path_to(int key);
        unsigned size();
        unsigned depth();
        void print();

        friend std::ostream& operator<<(std::ostream& stream, tree& RHS);


        void print_gtl();


        int maxdepth(node *node);

        node *getroot();

        void printPostorder(node *node);

        void printInorder(node *node);

        void printPreorder(node *node);
    };

#endif //CMPE130_TREE_H
