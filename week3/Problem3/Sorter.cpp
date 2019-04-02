#include "Sorter.h"
#include <vector>

std::vector<int> Sorter::quick_sort(std::vector<int> nums){
    do_quick_sort(nums, 0, nums.size());
    return nums;
}

std::vector<int> Sorter::bubble_sort(std::vector<int> nums){
    for(unsigned int i = 0; i < nums.size(); i++){
        for(unsigned int j = nums.size()-1; j > i; j--){
            if(nums[j] < nums[j-1]){
                int tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
            }
        }
    }
    return nums;
}

std::vector<int> Sorter::merge_sort(std::vector<int> nums){
    do_merge_sort(nums, 0, nums.size());
    return nums;
}

std::vector<int> Sorter::radix_sort(std::vector<int> nums){
    int max = 0;
    for(unsigned int i = 0; i < nums.size(); i++){
        if(nums[i] > max){
            max = nums[i];
        }
    }

    for(int exp = 1; max/exp > 0; exp*=10){
        // do count sort
        std::vector<int> tmp(nums.begin(), nums.end());
        
        // count
        int count[10] = {0};
        for(unsigned int i = 0; i < nums.size(); i++){
            count[(nums[i]/exp)%10]++;
        }
        for(int i = 1; i < 10; i++){
            count[i] += count[i-1];
        }

        for(int i = nums.size()-1; i >= 0; i--){
            nums[count[(tmp[i]/exp)%10]-1] = tmp[i];
            count[(tmp[i]/exp)%10] -= 1;
        }
    }

    return nums;
}

void Sorter::do_quick_sort(std::vector<int>& nums, int start, int end){
    if(end - start < 2){
        return;
    }

    int pivot = nums[(start+end)/2];
    int i = start - 1;
    int j = end;
    while(1){
        do{
            i++;
        }while(nums[i] < pivot);
        do{
            j--;
        }while(nums[j] > pivot);
        if(i >= j){
            break;
        }
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    do_quick_sort(nums, start, j);
    do_quick_sort(nums, j+1, end);
}

void Sorter::do_merge_sort(std::vector<int>& nums, int start, int end){
    if(end - start < 2){
        return;
    }

    int middle = (start + end) / 2;
    do_merge_sort(nums, start, middle);
    do_merge_sort(nums, middle+1, end);
    // merge
    std::vector<int> left(nums.begin()+start, nums.begin()+middle);
    std::vector<int> right(nums.begin()+middle, nums.begin()+end);
    unsigned int i = 0, j = 0;
    for(int k = start; k < end; k++){
        if(i < left.size() && (j >= right.size() || left[i] < right[j])){
            nums[k] = left[i];
            i++;
        }else{
            nums[k] = right[j];
            j++;
        }
    }
}

