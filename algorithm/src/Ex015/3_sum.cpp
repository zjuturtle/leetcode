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
    int search(vector<int>& nums, int start, int end, int num) {
        if (nums[start] <= num && num <= nums[end]) {
            while(true) {
                if (start == end && num != nums[end]) {
                    return -1;
                }
                if (start == end - 1) {
                    if (nums[start] == num)
                        return start;
                    if (nums[end] == num)
                        return end;
                    return -1;
                }
                int mid = (start + end)/2;
                if (nums[mid] > num) {
                    end = mid - 1;
                }
                if (nums[mid] < num) {
                    start = mid + 1;
                }
                if (nums[mid] == num) {
                    return mid;
                }
            }
        }
        return -1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> data;
        for (int i=0;i<nums.size();i++) {
            if (data.find(nums[i]) == data.end()) {
                data[nums[i]] = 1;
            } else {
                data[nums[i]] = data[nums[i]] + 1;
                if (nums[i] == 0 && data[nums[i]] > 3) {
                    data[nums[i]] = 3;
                }
                if (nums[i] != 0 && data[nums[i]] > 2) {
                    data[nums[i]] = 2;
                }
            }
        }

        nums.clear();
        for (auto &it : data) {
            for (int i=0;i<it.second;i++) {
                nums.push_back(it.first);
            }
        }

        sort(nums.begin(), nums.end());
        set<vector<int>> resultSet;

        for (int i=0; i + 2 < nums.size(); i++) {

            for (int j=i+2;j < nums.size();j++) {
                int searchResult = search(nums, i+1,j-1,-(nums[i]+nums[j]));
                if (searchResult!=-1) {
                    resultSet.insert(vector<int>{nums[i],nums[searchResult],nums[j]});
                }
            }
        }

        vector<vector<int>> result;
        for (auto &it : resultSet) {
            result.push_back(it);
        }

        return result;
    }
};

int main(){
    Solution s;
    vector<int> test= {-4,-1,-4,0,2,-2,-4,-3,2,-3,2,3,3,-4};
    s.threeSum(test);
}