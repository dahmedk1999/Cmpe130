//
// Created by Danish Khan on 9/15/2020.
//
#ifndef CMPE130_SORTS_H
#define CMPE130_SORTS_H

void swap(int* first, int* second);
void swap(int A[],int first, int second);
void quicksort(int A[], int l, int h);
int partition (int A[], int l, int h);
void merge(int A[],int l, int m, int h);
void mergesort(int A[],int l, int h);
void heapsort(int A[],int size);
void heapify(int A[],int i, int m);
#endif //CMPE130_SORTS_H
