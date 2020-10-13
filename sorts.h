//
// Created by Danish Khan on 9/15/2020.
//
#ifndef CMPE130_SORTS_H
#define CMPE130_SORTS_H

#include "faketree.h"

void swap(int* first, int* second);
void swap(int A[],int first, int second);
void quicksort(int A[], int l, int h);
int partition (int A[], int l, int h);
void merge(int A[],int l, int m, int h);
void mergeSort(int A[],int l, int h);
void heapsort(int A[],int size);
void heapify(int A[], int n, int i);
void heapify_min(int A[], int n, int i);
void cust_isheap(faketree t, int A[]);

#endif //CMPE130_SORTS_H
