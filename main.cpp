#include "infixpostfix.h"
#include "faketree.h"
#include "sorts.h"
#include <string>
#include <chrono>
#include "tree.h"
#define SIZE 10
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
void mergeheaplab(int loopx){faketree dummy_t{};
    int A[SIZE]={1,20,3,5,6,7,9,20,23,55};
    for(int i : A)
        cout<<i<<' ';
    cust_isheap(dummy_t,A);

    heapsort(A,SIZE);
    for(int i : A)
        cout<<i<<' ';
    cust_isheap(dummy_t,A);

    mergeSort(A,0,SIZE-1);
    for(int i : A)
        cout<<i<<' ';

    cout<<"\n########################\nBegin testing\n########################"<<endl;
    double avgM,avgH;
    for(int i=0;i<loopx;i++)
    {
        int s =100000;
        int rand100k[s];
        for(int i=0;i<=s;i++)rand100k[i]= (rand()%s) +1;
        auto start=std::chrono::high_resolution_clock::now();
        mergeSort(rand100k,0,s-1);
        auto stop=std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
        cout<<"\nMergesort: "<<time.count()<<" milliseconds."<<endl;
        avgM+=time.count();
        for(int i=0;i<=s;i++)rand100k[i]= (rand()%s) +1;
        start=std::chrono::high_resolution_clock::now();
        heapsort(rand100k,s);
        stop=std::chrono::high_resolution_clock::now();
        time = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
        cout<<"\nHeapsort: "<<time.count()<<" milliseconds."<<endl;
        avgH+=time.count();
    }
    cout<<"Average Mergesort time : "<<avgM/loopx<<" milliseconds"<<endl;
    cout<<"Average Heapsort time  : "<<avgH/loopx<<" milliseconds"<<endl;
}
void treelab(){
    tree newtree;
    string treestring;
    newtree.insert(100);
    newtree.insert(150);
    newtree.insert(200);
    newtree.insert(100);
    newtree.insert(50);
    newtree.insert(40);
    newtree.insert(20);
    newtree.printPreorder(newtree.getroot());
    cout<<endl;
}



int main(){

return 0;
}
