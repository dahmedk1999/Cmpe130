//
// Created by Danish Khan on 9/15/2020.
//
#include "sorts.h"


void swap(int* first, int* second){
    int temp = *first;
    *first=*second;
    *second=*first;
}
void swap(int A[],int first, int second) {
    int temp = A[first];
    A[first] = A[second];
    A[second] = temp;
}
int partition (int A[], int l, int h){
int pivot=A[h];
int i=l-1;
for(int j = l; j<=h-1; j++)
    if(A[j]<=pivot)
    {
        i++;
        swap(&A[i],&A[j]);
    }
swap(&A[i+1],&A[h]);
    return i+1;
}

void quicksort(int A[], int l, int h){
if (l<h){
    int index= partition(A,l,h);
    quicksort(A,l,index-1);
    quicksort(A,index+1,h);
}
}

void heapify(int A[], int n, int i) {
    int root = i;
    int left = 2*i;
    int right= 2*i+1;
    if (left < n && A[left] < A[root])
        root= left;
    if (right < n && A[right] < A[root])
        root = right;

    if (root != i) {
        swap(A,i,root);
        heapify(A, n, root);
    }

}

void heapsort(int A[],int size) {
    for (int i =size/2-1;i>=0;i--)
        heapify(A,size,i);

    for(int i=size-1;i>0;i--)
    {
        swap(A,0,i);
        heapify(A,i,0);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
//subarray
    int L_subarray[n1], R_subarray[n2];

//subarray filling
    for (i = 0; i < n1; i++)
        L_subarray[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R_subarray[j] = arr[m + 1 + j];
    i=j=0;k=l;
    while (i < n1 && j < n2) {
        if (L_subarray[i] <= R_subarray[j]) {
            arr[k] = L_subarray[i];
            i++;
        }
        else {
            arr[k] = R_subarray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {//copy left subarray
        arr[k] = L_subarray[i];
        i++;
        k++;
    }
    while (j < n2) {//copy left subarray
        arr[k] = R_subarray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
    }
}

void cust_isheap(faketree t, int A[]){
if(t.Maxheap(A, sizeof(A)))
    std::cout<<"\nA is a maxheap"<<endl;
else if (t.minheap(A, sizeof(A)))
    std::cout<<"\nA is a mixheap"<<endl;
else std::cout<<"\nA is not a heap"<<endl;
}

void heapify_min(int *A, int n, int i) {
    int root = i;
    int left = 2*i+1;
    int right= 2*i+2;
    if (left < n && A[left] < A[root])
        root= left;
    if (right < n && A[right] < A[root])
        root = right;

    if (root != i) {
        swap(A,i,root);
        heapify(A, n, root);
    }

}
