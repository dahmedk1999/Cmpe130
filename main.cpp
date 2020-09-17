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

#define size 10
int main(){
tree dummy_t{};
int A[size]={1,20,3,5,6,7,9,20,23,55};
for(int i : A)
    cout<<i<<' ';
cust_isheap(dummy_t,A);

heapsort(A,size);
for(int i : A)
    cout<<i<<' ';
cust_isheap(dummy_t,A);

mergeSort(A,0,size-1);
for(int i : A)
cout<<i<<' ';
return 0;
}
