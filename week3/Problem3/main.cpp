#include "Sorter.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

void show_array(std::vector<int> n, int size){
    std::cout << "Current array: ";
    for(int i = 0; i < size; i++){
        std::cout << n[i] << ' ';
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> nums;
    std::vector<int> res;
    std::string methods[4] = {"Bubble sort", "Quick sort", "Merge sort", "Radix sort"};
    int array_size = 10000;
    int repeat_time = 20;

    srand(time(0));
    for(int i = 0; i < array_size; i++){
        nums.push_back(rand());
    }

    Sorter sorter;

    double time_used[4]; 

    std::cout << "4 sorting methods are being tested using an array of " << array_size << " randomly generated integers." << std::endl;
    // test bubble sort
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < repeat_time; i++){
        sorter.bubble_sort(nums);
    }
    auto end = std::chrono::high_resolution_clock::now();
    time_used[0] = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // test quick sort
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < repeat_time; i++){
        res = sorter.quick_sort(nums);
    }
    end = std::chrono::high_resolution_clock::now();
    time_used[1] = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // test merge sort
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < repeat_time; i++){
        sorter.merge_sort(nums);
    }
    end = std::chrono::high_resolution_clock::now();
    time_used[2] = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // test radix sort
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < repeat_time; i++){
        sorter.radix_sort(nums);
    }
    end = std::chrono::high_resolution_clock::now();
    time_used[3] = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();


    for(int i = 0; i < 4; i++){
        time_used[i] *= 1e-9; // transform to seconds
    }

    // find minimum sort time
    double maxTime = -1.0;
    int worst_method;
    for(int i = 0; i < 4; i++){
        if(maxTime < time_used[i]){
            maxTime = time_used[i];
            worst_method = i;
        }
    }

    // output
    std::cout << "The slowest method is " << methods[worst_method] << ", which uses " << maxTime << "s" << std::endl;
    for(int i = 0; i < 4; i++){
        if(i != worst_method){
            int improvement = maxTime / time_used[i];
            std::cout << methods[i] << " improved " << improvement << " times over " << methods[worst_method] << " with " << time_used[i] << "s" << std::endl;
        }
    }

    return 0;
}
