#include <vector>

class Sorter{
    public:
        std::vector<int> quick_sort(std::vector<int> nums);
        std::vector<int> bubble_sort(std::vector<int> nums);
        std::vector<int> merge_sort(std::vector<int> nums);
        std::vector<int> radix_sort(std::vector<int> nums);

    private:
        void do_quick_sort(std::vector<int>& nums, int start, int end);
        void do_merge_sort(std::vector<int>& nums, int start, int end);

};
