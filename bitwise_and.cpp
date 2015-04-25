// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <vector>
#include <iostream>
#include <cassert>
class Solution {
   public:
        int rangeBitwiseAnd(int m, int n) {

            if (m == n) {
                return m;
            }

            if (m > n) {
                int tmp = m;
                m = n;
                n = tmp;
            }

            int gap = n - m;
            int num = m;
            std::vector<int> bits;
            while (num > 0) {
                int rem = num % 2;
                bits.push_back(rem);
                num /= 2;
            }

            int exp = 1;
            for (int i = 0; i < bits.size(); ++i) {
                if (bits[i] == 0) {
                    bits[i] = 0;
                }
                else if (gap >= exp) {
                    bits[i] = 0;
                }
                exp *= 2;
            }

            exp = 1;
            int result = 0;
            for (int i = 0; i < bits.size(); ++i) {
                result += bits[i] * exp;
                exp *= 2;
            }
            return result;
        }
};

int main(int argc, char **argv) {
    Solution *sol = new Solution();
    assert(sol->rangeBitwiseAnd(5,7) == 4);
    assert(sol->rangeBitwiseAnd(2,3) == 2);
    assert(sol->rangeBitwiseAnd(2,2) == 2);
    assert(sol->rangeBitwiseAnd(3,2) == 2);
//    assert(sol->rangeBitwiseAnd(3,4) == 0);
    std::cout << -9%7 << std::endl;
}
