// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//Given an array of integers, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2
//
ass Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> sumVec;
            vector<int> indexVec;
            vector<int> num = numbers;
            if(numbers.size() < 2) return sumVec;
            sort(numbers.begin(), numbers.end());
            int i = 0;
            int j = numbers.size() - 1;
            while(i < j) {
                if(numbers[i] + numbers[j] == target) {
                    sumVec.push_back(numbers[i]);
                    sumVec.push_back(numbers[j]);
                    break;
                }
                else if(numbers[i] + numbers[j] < target) i++;
                else j--;
            }
            if(sumVec.size() < 2) return indexVec;
            for(int i = 0 ; i < num.size(); i++) {
                if(num[i] == sumVec[0]  || num[i] == sumVec[1]) indexVec.push_back(i+1);

            }
            return indexVec;
        }
};
