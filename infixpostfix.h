#include <vector>
#include <string>
#include <iostream>
using namespace std;

class stack{
public:
    stack();
    vector<char> s;
    int index=0;
    void push(char input_operand);
    void pop();
    char top();
    bool isempty() const;
};

class postfixer{
public:

    stack operatorStack;
    string postfix;

    string parser(string infix);
};