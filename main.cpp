#include "infixpostfix.h"
#include "tree.h"
#include "sorts.h"

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

#define size 7
int main(){
tree dummy_t{};
int A[size]={30,10,100,5,7,9,2};

if(dummy_t.Maxheap(A, size))
    std::cout<<"A is a maxheap"<<endl;
else
    std::cout<<"A is not a maxheap"<<endl;

heapsort(A,size);
for(int i=0;i<size;i++)
    cout<<A[i]<<' ';
return 0;
}
