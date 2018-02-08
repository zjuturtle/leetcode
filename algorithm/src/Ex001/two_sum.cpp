//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1, index2;
        int size = nums.size();
        vector<int> res;
        for (index1 = 0; index1 < size ; index1 ++) {
            for (index2 = index1 + 1; index2 < size; index2++) {
                if ((nums[index1]+nums[index2]) == target){
                    res.push_back(index1);
                    res.push_back(index2);
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    getchar();
    return 0;
}


