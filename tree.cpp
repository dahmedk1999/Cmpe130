//
// Created by Danish Khan on 9/29/2020.
//

#include "tree.h"
#include <iostream>
#include <math.h>
#include <string>
    void clear(node *to_clear);
    tree::tree() {
        root = nullptr;
        tree_size = 0;
    }

    node* constr_h(node*current, node*rhs)
    {

        if(rhs== nullptr)
            return current;
        else
        {
            current=new node(rhs->data);
            constr_h(current->left,rhs->left);
            constr_h(current->right,rhs->right);
        }
    }
    tree::tree(const tree &copy)
    {
        if(copy.root== nullptr)root= nullptr;
        else constr_h(root,copy.root);
    }
    tree::~tree() {
        clear(root);
    }

////////////////////////////////////// Auxiliary functions
    void node_print_gtl(node *top)
    {
        if (top == nullptr)
            return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++)
            std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr)
            return;
        if (to_clear->left != nullptr)
            clear(to_clear->left);
        if (to_clear->right != nullptr)
            clear(to_clear->right);
        delete to_clear;
    }
    node *search(node*root, int key)
    {
        if(root==nullptr||root->data==key)
            return root;
        if(root->data<key)
            return search(root->right,key);
        else
            return search(root->left,key);
    }

    int searchlevel(node*root, int key)
    {
        if(search(root,key)== nullptr)
            return -1;
        if(root== nullptr||root->data==key)
            return 0;
        if(root->data<=key)
            return 1+searchlevel(root->right,key);
        else
            return 1+searchlevel(root->left,key);
    }
//////////////////////////////////////////////////////////////
    // Insert
    void node_insert(node *temp, int key){
        if (key < temp->data && temp->left != nullptr) {
            node_insert(temp->left, key);
        }else if(key < temp->data){
            auto newNode = new node(key);
            temp->left = newNode;


        }else if(key > temp->data && temp->right != nullptr) {
            node_insert(temp->right, key);
        }else if(key > temp->data){
            auto newNode = new node(key);
            temp->right = newNode;
        }
    }
    void insert_helper_freq(node* temp,int value)
    {
        if(value==temp->data)
            temp->frequency++;
        else if(value<temp->data)
            insert_helper_freq(temp->left,value);
        else if(value>temp->data)
            insert_helper_freq(temp->right,value);

    }

    void tree::insert(int value)
    {
        auto temp= root;
        if(root== nullptr) {
            auto temp1 = new node(value);
            root=temp1;
            tree_size++;
            cost+=value;
        }
        else if (in_tree(value))
        {
            cost+=value;
            tree_size++;
            insert_helper_freq(temp,value);
        }
        else
        {
            cost+=value;
            node_insert(temp, value);
            tree_size++;
        }
    }

    bool tree::remove(int key)
    {
        if(in_tree(key))
        {
            auto temp=search(root,key);
            if(temp->frequency>=0) {tree_size--;temp->frequency--;}
            return true;
        }

        return false;
    }

    int tree::level(int key)
    {
        return searchlevel(root,key);
    }

    void *path(node*root, int key)
    {
        if(root->data==key)
            std::cout<<root->data<<"\n";
        else if(key<root->data)
        {
            std::cout<<root->data<<" -> ";
            path(root->left,key);
        }
        else if(key>root->data)
        {
            std::cout<<root->data<<" -> ";
            path(root->right,key);
        }
        else std::cout<<"";
    }
    void tree::path_to(int key)
    {
        if(in_tree(key))
            path(root,key);
        else std::cout<<"";
    }

    // Number of items in the tree
    unsigned tree::size()
    {
        return tree_size;
    }

    unsigned findepth(node* N,int currentD)
    {
        if(!N) return currentD;

        unsigned leftd = findepth(N->left,currentD+1);
        unsigned rightd= findepth(N->right,currentD+1);

        return leftd>rightd ? (leftd) : (rightd);
    }

    unsigned tree::depth()
    {
        if(!root || tree_size==0)return 0;
        return findepth(root,0)-1;
    }
    int tree::maxdepth(node * node)
    {
        if(!node) return 0;

        int leftd = maxdepth(node->left);
        int rightd= maxdepth(node->right);

        return leftd>rightd ? (leftd+1) : (rightd+1);
    }

    bool tree::in_tree(int key)
    {
        return search(root, key) != nullptr;
    }
    node *tree::getroot(){return root;}
    int tree::get_frequency(int key)
    {
        if(in_tree(key))
            return search(root,key)->frequency;
        else return 0;
    }
    std::string in_order(node* root)
    {
        std::string temp;
        if (root == nullptr)
            return temp;
        in_order(root->left);
        for (int i = 0; i < root->frequency; i++)
        {
            std::cout << root->data << " ";
            temp+=std::to_string(root->data);
        }
        in_order(root->right);
    }


    std::string tree::to_string(){
        std::cout<<"\n";
        return in_order((root));
    }

    void node_print_ltg(node *root)
    {
        if (root == nullptr)
            return;

        node_print_ltg(root->left);
        for (int i = 0; i < root->frequency; i++)
            std::cout << root->data << " ";
        node_print_ltg(root->right);

    }

    void tree::print()
    {
        node_print_ltg(root);

        std::cout<<"\n";
        std::cout<<"Total Cost= "<<cost<<std::endl;
    }

    std::ostream &operator<<(std::ostream &stream, tree &RHS)
    {
        std::string outString=in_order(RHS.root);
        stream << outString << std::endl;
    }

    void op_helper(node*current, node*rhs)
    {
        if(rhs)
        {
            current=new node(rhs->data);
            if(rhs->right)
            {
                current->right=new node(rhs->right->data);
                op_helper(current->right, rhs->right);
            }
            if(rhs->left)
            {
                current->left=new node(rhs->left->data);
                op_helper(current->left, rhs->left);
            }
        }
    }

void tree::printPostorder(node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    std::cout<< node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void tree::printInorder(node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

void tree::printPreorder(node* node)
{
    if (node == NULL)
        return;
    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }
