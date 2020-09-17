#include "infixpostfix.h"
#include "tree.h"
#include "sorts.h"
#include <chrono>

#define size 10
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
void mergeheaplab(int loopx){tree dummy_t{};
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

int main(){

return 0;
}
