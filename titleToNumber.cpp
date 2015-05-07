// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//Related to question Excel Sheet Column Title

//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//    A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28 /
#include <string>
#include <cassert>
using namespace std;
class Solution {
    public:
        int titleToNumber(string s) {
            if (s.size() == 0) {
                return 0;
            }

            int carry = 1;
            int res = 0;
            for (int i = s.size() - 1; i >= 0; --i) {
                res += (s[i]-'A' + 1) * carry;
                carry *= 26;
            }
            return res;
        }
};

int main(int argc, char** argv) {
    Solution sol;
    assert(sol.titleToNumber("A") == 1);
    assert(sol.titleToNumber("AA") == 27);
    assert(sol.titleToNumber("") == 0);
}
