#include <chrono>
#include "infixpostfix.h"
#include "faketree.h"
#include "sorts.h"

#include "tree.h"
#include "redblack.h"
#include "disjoint.h"
#include "maze.h"
#include "FloydWarshall.h"
#include "recursion_memoization.h"

using namespace std;
#define SIZE 30

void infixpostfixlab() {
    postfixer p;
    postfixer p2;
    postfixer p3;
    string infix = "a+(b-c*d)/d";
    p.parser(infix);
    infix = "(a-b*c)/(d*e*f+g)";
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
    //newtree.printPreorder(newtree.getroot());
    newtree.print();
    cout<<endl;
}
void redblack(){
    int A[]={100, 200, 150, 170, 165, 180, 220, 163, 164};
    int N = sizeof(A) / sizeof(A[0]);
    quicksort(A, 0, N - 1);
    for(int i=0;i<N;i++)
        cout<<A[i]<<endl;



    RBTree bst;
    bst.insert(100);
    bst.insert(200);
    bst.insert(150);
    bst.insert(170);
    bst.insert(165);
    bst.insert(180);
    bst.insert(220);
    bst.insert(163);
    bst.insert(164);

    bst.preorder();

}
void mazeprint() {

    Maze M(SIZE);
    M.printMaze();
}
void FloydWarshall(){
    int graph[4][4]={{0,9,-4,999999},
                     {6,0,999999,2},
                     {999999,5,0,999999},
                     {999999,999999,1,0}};
    print_Warshall(graph);
    cout<<endl;
    shortest_path(graph);
}
void RMT_fib_test(int sizeRMT)
{
    cout<<"Selected fib number:"<<sizeRMT;
extern unsigned long tabulation_array[1024];
extern unsigned long memoization_array[1024];

for(int i=0;i<1024;i++)tabulation_array[i]=-1;
for(int i=0;i<1024;i++)memoization_array[i]=-1;
unsigned long answer;
//Recursion timing
auto start_timer = std::chrono::high_resolution_clock::now();
answer=recursion_fibonacci(sizeRMT);
auto stop_timer = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_timer-start_timer);
cout<<"\nRecursion fibonacci number:"<<answer<<"\nDuration: "<<duration.count()<<" nanoseconds\n";

//Memoized fibonacci timing
auto start_timer1 = std::chrono::high_resolution_clock::now();
answer=memoize_fibonacci(sizeRMT);
auto stop_timer1 = std::chrono::high_resolution_clock::now();
auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_timer1-start_timer1);
cout<<"\nMemoized fibonacci number:"<<answer<<"\nDuration: "<<duration1.count()<<" nanoseconds\n";

//Tabulated fibonacci timing
auto start_timer2 = std::chrono::high_resolution_clock::now();
answer=tabulation_fibonacci(sizeRMT);
auto stop_timer2 = std::chrono::high_resolution_clock::now();
auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_timer2-start_timer2);
cout<<"\nTabulated fibonacci number:"<<answer<<"\nDuration: "<<duration2.count()<<" nanoseconds\n";

}

int main(){

RMT_fib_test(20);
return 0;
}
