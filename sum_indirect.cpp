#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#include "sum_indirect.h"



void 
setup(int64_t N, uint64_t A[])
{
       // Create a vector of unique values from 0 to N-1
    std::vector<uint64_t> uniqueValues(N);
    for (uint64_t i = 0; i < N; ++i) {
        uniqueValues[i] = i;
    }

    // Shuffle the vector to randomize the order
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(uniqueValues.begin(), uniqueValues.end(), gen);

    // Copy the shuffled values to the array A
    for (int64_t i = 0; i < N; ++i) {
        A[i] = uniqueValues[i];
    }
}

int64_t
sum(int64_t N, uint64_t A[])
{
   int64_t result = 0;
   int64_t ind = 0;
    for (int64_t i = 0; i < N; ++i) {
         int64_t e = A[ind];
        result += e;
        ind = e;
    }

   return result;
}

