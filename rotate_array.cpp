// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
//
//Note:
//Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
#include <iostream>
class Solution {
    public:
        void rotate(int nums[], int n, int k) {
            if (nums == NULL || n <= 0) {
                return;
            }

            k = k % n;
            if (k > 0) {
                reverse(nums, 0, n-k-1);
                reverse(nums, n-k, n-1);
                reverse(nums, 0, n-1);
            }

            if (k < 0) {
                k = -k;
                reverse(nums, 0, k-1);
                reverse(nums, k, n-1);
                reverse(nums, 0, n-1);
            }
            return;
        }

        void reverse(int nums[], int left, int right) {
            while (left < right) {
                int tmp = nums[left];
                nums[left++] = nums[right];
                nums[right--] = tmp;
            }
        }
};


void print_array(int nums[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    Solution sol;
    sol.rotate(nums, 7, 3);
    print_array(nums, 7);
    sol.rotate(nums, 7, -3);
    print_array(nums, 7);
    sol.rotate(nums, 7, -10);
    print_array(nums, 7);
    sol.rotate(nums, 7, 10);
    print_array(nums, 7);
    sol.rotate(nums, 7, 0);
    print_array(nums, 7);
}
