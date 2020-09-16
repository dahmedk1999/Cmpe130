//
// Created by Danish Khan on 9/15/2020.
//

#include "tree.h"


bool tree::Maxheap(int A[], int size) {//dummy tree
    bool left = false;
    bool right= false;

    for(int i=0;i<size/2;i++)
    {
        if(i==0)//root case
        {
            if(A[1]!= NULL)//first child of root
                left=true;
            if(A[2]!=NULL)//2nd child of root
                right=true;
            if(left && right)
                if(A[i]<A[1] && A[i]<A[2])
                    return false;

            if(left && !right)///!complete tree
                if(A[i]<A[1])
                    return false;
        }
        else
        {//child detection (2i) (2i+1)
            if(A[(2*i +1)]!= NULL)
                right=true;
            if(A[2*i]!= NULL)
                left=true;

            if(left && right)
                if(A[i]<A[2*i] && A[i] <A[2*i+1])
                    return false;
            if(left && !right)
                if(A[i]<A[2*i])
                    return false;
        }
    }
    return true;
}

bool tree::minheap(int *A, int size) {
    bool left = false;
    bool right= false;

    for(int i=0;i<size/2;i++)
    {
        if(i==0)//root case
        {
            if(A[1]!= NULL)//first child of root
                left=true;
            if(A[2]!=NULL)//2nd child of root
                right=true;
            if(left && right)
                if(A[i]>A[1] && A[i]>A[2])
                    return false;

            if(left && !right)///!complete tree
                if(A[i]>A[1])
                    return false;
        }
        else
        {//child detection (2i) (2i+1)
            if(A[(2*i +1)]!= NULL)
                right=true;
            if(A[(2*i)]!= NULL)
                left=true;

            if(left && right)
                if(A[i]>A[(2*i)] && A[i]>A[(2*i+1)])
                    return false;
            if(left && !right)
                if(A[i]>A[(2*i)])
                    return false;
        }
    } return true;
}
