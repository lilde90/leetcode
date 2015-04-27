// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

//You may assume that the array is non-empty and the majority element always exist in the array.
#include <vector>
#include <cassert>
using namespace std;
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int res;
            int count = 0;
            for(int i = 0; i < nums.size(); ++i) {
                if (count == 0) {
                    count = 1;
                    res = nums[i];
                } else {
                    if (res == nums[i]) {
                        count++;
                    } else {
                        count--;
                    }
                }
            }
            return res;
        }
};

int main(int argc, char *argv[]) {
    vector <int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    Solution sol;
    assert(sol.majorityElement(nums) == 2);
}
