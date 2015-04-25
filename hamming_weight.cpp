// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//
//For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
#include <cassert>
class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int cnt = 0;
            while(n) {
                n &= (n-1);
                cnt++;
            }
            return cnt;
        }
};

int main(int argc, char **argcv) {
    Solution sol;
    assert(sol.hammingWeight(11) == 3);
}
