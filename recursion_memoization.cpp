//
// Created by Danish Khan on 11/28/2020.
//
#include <iostream>
#include "recursion_memoization.h"

unsigned long memoization_array[1024];
unsigned long tabulation_array[1024];


unsigned long recursion_fibonacci(unsigned long N) {
      if(N==1)return 1;
      else if(N==0)return 0;
      else
          return recursion_fibonacci(N - 1) + recursion_fibonacci(N - 2);
}
unsigned long memoize_fibonacci(unsigned long N) {
    if (memoization_array[N] == -1)
        if (N <= 1) { memoization_array[N] = N;}
        else {
            memoization_array[N] = memoize_fibonacci(N - 2) + memoize_fibonacci(N - 1);
        }
    return memoization_array[N];
}

unsigned long tabulation_fibonacci(unsigned long N) {
    tabulation_array[0] = 0;
    tabulation_array[1] = 1;
    for(int i = 2; i <= N; i++)
       tabulation_array[i] = tabulation_array[i - 1] + tabulation_array[i - 2];
    return tabulation_array[N];
}

