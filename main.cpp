#include "infixpostfix.h"
#include "tree.h"

void infixpostfixlab(){
    postfixer p;
    postfixer p2;
    postfixer p3;
    string infix= "a+(b-c*d)/d";
    p.parser(infix);
    infix= "(a-b*c)/(d*e*f+g)";
    p2.parser(infix);
    infix= "a/b * (c+(d-e))";
    p3.parser(infix);
}


int main(){
tree dummy_t{};
int A[5]={10,5,7,3,1};

if(dummy_t.Maxheap(A,5))
    std::cout<<"A is a maxheap"<<endl;
else
    std::cout<<"A is not a maxheap"<<endl;

return 0;
}