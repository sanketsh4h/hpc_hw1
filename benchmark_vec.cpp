//
// (C) 2022-2023, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
//    over different problem sizes
//
// usage: no command line arguments
// set problem sizes, block sizes in the code below

#include <algorithm>
#include <chrono>
#include <iomanip>   
#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#include "sum_vector.h"

extern void setup(int64_t N, uint64_t A[]);
extern int64_t sum(int64_t N, uint64_t A[]);

/* The benchmarking program */
int main(int argc, char** argv) 
{
   std::cout << std::fixed << std::setprecision(3);

const int64_t MAX_PROBLEM_SIZE = 1 << 28;  // 256M
std::vector<int64_t> problem_sizes;
problem_sizes.push_back(1<<23);
problem_sizes.push_back(1<<24);
problem_sizes.push_back(1<<25);
problem_sizes.push_back(1<<26);
problem_sizes.push_back(1<<27);
problem_sizes.push_back(1<<28);
   
   std::vector<uint64_t> A(MAX_PROBLEM_SIZE);

   int64_t t;
   int n_problems = problem_sizes.size();

   /* For each test size */
   for (int64_t n : problem_sizes) 
   {
      printf("Working on problem size N=%lld \n", n);

      // invoke user code to set up the problem
      setup(n, &A[0]);

      // insert your timer code here
        auto start_time = std::chrono::high_resolution_clock::now();

      // invoke method to perform the sum
      t = sum(n, &A[0]);

      // insert your end timer code here, and print out elapsed time for this problem size
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
         int64_t time_taken = duration.count();
        printf(" Elapsed time = %lld milliseconds \n", time_taken);

      int64_t flops = n*2;
      int64_t mflops_per_sec = flops/(1000*time_taken);;
      printf("MFLOP/s = %d\n", mflops_per_sec);

      int bytes_accessed = 8*n;
      int64_t max_bw = 204LL * (1LL << 30);
      float bw = 1000*(static_cast<float>(bytes_accessed)/time_taken);
      float perc_bw = bw/(max_bw);
      // printf("Bandwidth: %f", bw);
      // printf("Max Bandwidth: %d", max_bw);
      printf("Percentage Bandwidth: %f\n", perc_bw);

      int16_t mem_acc_per_it = 1;
      int memory_accesses = mem_acc_per_it*n;
      
      float latency = (1000000*time_taken)/memory_accesses;
      printf("Memory Accesses: %d\n", memory_accesses);
      printf("Latency: %f nanoseconds\n", latency);

   } // end loop over problem sizes
}

// EOF
