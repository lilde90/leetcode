// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example: 19 is a happy number
//
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100
//1^2 + 0^2 + 0^2 = 1
#include <vector>
#include <cassert>
class Solution {
    public:
        bool isHappy(int n) {
            std::vector<int> path;
            while (n != 1) {
                int num = n;
                int sum = 0;
                while (num > 0) {
                    int rem = num % 10;
                    sum += rem * rem;
                    num /= 10;
                }

                if (find(path.begin(), path.end(), sum) != path.end()) {
                    return false;
                } else {
                    n = sum;
                    path.push_back(sum);
                }
            }
            return true;
        }
};

int main(int argc, char **argv) {
    Solution sol;
    assert(sol.isHappy(19));
    assert(!sol.isHappy(20));
}
