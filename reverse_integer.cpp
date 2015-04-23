// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@baidu.com)
//
//Reverse digits of an integer.

//Example1: x = 123, return 321
//Example2: x = -123, return -321
class Solution {
public:
    int reverse(int x) {
        int n = x;
        unsigned long long result = 0;
        int m;
        int sign = 1;
        if(x < 0) sign = -1;
        do {
            m = n % 10;
            if(m < 0) m = -m;
            result = result * 10 + m;
            n = n / 10;
        }while( n != 0);
        if (n > 0x7fffffff && sign == -1)
		    return 0x80000000;
	    if (n >= 0x7fffffff && sign == 1)
		    return 0x7fffffff;
		return sign * result;
    }
};
