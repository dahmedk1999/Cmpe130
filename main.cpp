#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <cctype>
using std::vector;
using std::string;
using std::cout;

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
void stack::push(char input_operand)
{
    //cout<<"Pushed: "<<input_operand<<"\n";
    s.push_back(input_operand);
    index++;
}
char stack::top(){
    if(!s.empty()) {
        //cout << "Top of stack is: " << s.back() << "\n";
        return s.back();
    }
}

void stack::pop()
{
    if(!s.empty()){
        //cout << "Popped: " << s.back() << "\n";
        s.pop_back();
        index--;
    }
}

bool stack::isempty() const {
    return !index;
}

stack::stack() {
    index=0;
    s.clear();
}

class postfixer{
public:

stack operatorStack;
string postfix;

string parser(string infix);
};

string postfixer::parser(string infix)
{
    string returnstring;
    while(infix[0]!='\0')
    {
    if(infix[0]==' ')
    {
        //cout<<"removed whitespace\n";
        infix.erase(infix.begin());
    }
    else {
        returnstring.push_back(infix[0]);
        infix.erase(infix.begin());
    }

    }
    cout<<"Infix equation "<<returnstring<<'\n';

    ///////
    while (!returnstring.empty())
    {
        if ((   returnstring[0]== '*' || returnstring[0] == '/'  ||
                returnstring[0]== '-' || returnstring[0] == '+') || returnstring[0] == '(')
        {
            while ((!operatorStack.isempty() &&(
                    (operatorStack.top() == '*' && returnstring[0] == '/') ||
                    (operatorStack.top() == '*' && returnstring[0] == '+') ||
                    (operatorStack.top() == '*' && returnstring[0] == '-') ||
                    (operatorStack.top() == '*' && returnstring[0] == '*') ||

                    (operatorStack.top() == '/' && returnstring[0] == '*') ||
                    (operatorStack.top() == '/' && returnstring[0] == '-') ||
                    (operatorStack.top() == '/' && returnstring[0] == '/') ||
                    (operatorStack.top() == '/' && returnstring[0] == '+') ||

                    (operatorStack.top() == '+' && returnstring[0] == '+') ||
                    (operatorStack.top() == '+' && returnstring[0] == '-') ||

                    (operatorStack.top() == '-' && returnstring[0] == '-')||
                    ((operatorStack.top()== '-' && returnstring[0] == '+')
                     && returnstring[0] != '('))))
            {
                postfix.push_back(operatorStack.top());
                operatorStack.pop();
            }//compare each op precedence combination
            operatorStack.push(returnstring[0]);

        } else if (returnstring[0] == ')')
        {
            while (operatorStack.top() != '(')
            {
               // cout<<"Postfixed char "<<operatorStack.top()<<'\n';
                postfix.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else
        {
            postfix.push_back(returnstring[0]);
        }
        returnstring.erase(returnstring.begin());

    }

    while (!operatorStack.isempty() && operatorStack.top()!='\0')
    {
        postfix.push_back(operatorStack.top());
        operatorStack.pop();
    }

    cout<<"Postfix result: "<<postfix<<'\n';
    return postfix;
}

int main()
{
    postfixer p;
    postfixer p2;
    postfixer p3;
    string infix= "a+(b-c*d)/d";
    p.parser(infix);
    infix= "(a-b*c)/(d*e*f+g)";
    p2.parser(infix);
    infix= "a/b * (c+(d-e))";
    p3.parser(infix);

return 0;
}
