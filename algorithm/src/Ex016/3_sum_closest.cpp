//
// Created by 雷京颢 on 2020/3/7.
//
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int start, int end, int num){
        if (num <= nums[start]) {
            return start;
        }

        if (nums[end] <= num) {
            return end;
        }

        while(true) {
            if (start == end && num != nums[end]) {
                return end;
            }
            if (start == end - 1) {
                if (num - nums[start] >= nums[end] - num) {
                    return end;
                } else {
                    return start;
                }
            }

            int mid = (start + end)/2;
            if (nums[mid] > num) {
                end = mid ;
            }
            if (nums[mid] < num) {
                start = mid;
            }
            if (nums[mid] == num) {
                return mid;
            }
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestDiff = INT_MAX;
        int closestI = -1;
        int closestJ = -1;
        int closestMid = -1;
        bool lastIncreasedI = false;
        for (int i=0;i < nums.size()-2;i++) {
            for (int j=i+2;j<nums.size();j++) {
                if (i==0 && j ==5){
                    cout << "d";
                }
                int searchTarget = target - nums[i] - nums[j];
                int searchMid = search(nums, i + 1, j - 1, searchTarget);
                int searchDiff = abs(target - (nums[i] + nums[j] + nums[searchMid]));
                if (closestDiff > searchDiff) {
                    closestDiff = searchDiff;
                    closestI = i;
                    closestJ = j;
                    closestMid = searchMid;
                }
            }
        }

        return nums[closestI] + nums[closestJ] + nums[closestMid];
    }
};

int main(){
    Solution s;
    vector<int> test= {1,6,9,14,16,70};
    s.threeSumClosest(test, 81);
}
