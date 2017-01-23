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


