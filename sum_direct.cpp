#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "sum_direct.h"

void setup(int64_t N, uint64_t A[]) {
    // Allocate memory and initialize array with random values
   //  std::random_device rd;
   //  std::mt19937 gen(rd());
   //  std::uniform_int_distribution<uint64_t> dis(1, 100); // Adjust range as needed

   //  for (int64_t i = 0; i < N; ++i) {
   //      A[i] = dis(gen);
   //  }
}

int64_t sum(int64_t N, uint64_t A[]) {
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i) {
        result += i;
    }
    return result;
}

// int main() {
//     const int64_t N = 1000000; // Adjust problem size as needed
//     uint64_t* A = new uint64_t[N];

//     setup(N, A);

//     auto start = std::chrono::high_resolution_clock::now();
//     int64_t result = sum(N, A);
//     auto end = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

//     double seconds = duration.count() / 1e6; // Convert to seconds

//     // Calculate MFLOP/s
//     double mflops = (2.0 * N) / (1e6 * seconds);

//     // Calculate memory bandwidth utilization percentage
//     // Replace memory_bandwidth with the appropriate value for your system
//     double memory_bandwidth = 100.0; // in GB/s
//     double memory_utilization = (N * sizeof(uint64_t)) / (seconds * memory_bandwidth * 1e9) * 100;

//     // Calculate estimated memory latency
//     // Replace memory_latency with the appropriate value for your system
//     double memory_latency = 100.0; // in ns
//     double estimated_latency = (N * sizeof(uint64_t)) / (memory_bandwidth * 1e9) * memory_latency;

//     std::cout << "Result: " << result << std::endl;
//     std::cout << "Time (s): " << seconds << std::endl;
//     std::cout << "MFLOP/s: " << mflops << std::endl;
//     std::cout << "Memory Bandwidth Utilization (%): " << memory_utilization << std::endl;
//     std::cout << "Estimated Memory Latency (ns): " << estimated_latency << std::endl;

//     delete[] A;
//     return 0;
// }
