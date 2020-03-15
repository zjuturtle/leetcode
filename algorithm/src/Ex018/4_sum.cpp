//
// Created by 雷京颢 on 2020/3/15.
//
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    struct Pack{
        int indexA;
        int indexB;
    };

    bool individual(const Pack &a, const Pack &b){
        return a.indexA != b.indexA && a.indexA != b.indexB &&
               a.indexB != b.indexA && a.indexB != b.indexB;
    }

    vector<int> merge(const vector<int> &nums, const Pack &a, const Pack &b) {
        vector<int> res = {nums[a.indexA], nums[a.indexB],nums[b.indexA], nums[b.indexB]};
        sort(res.begin(), res.end());
        return res;
    }

    void printVector(const vector<int> &a) {
        for (auto it : a) {
            cout << it << " ";
        }
        cout << endl;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int, vector<Pack>> data;
        for (int i=0;i+1<nums.size();i++) {
            for (int j=i+1;j<nums.size();j++) {
                int sum = nums[i] + nums[j];
                if (data.find(sum) == data.end()) {
                    data[sum] = vector<Pack>{Pack{i,j}};
                } else {
                    data[sum].emplace_back(Pack{i, j});
                }
            }
        }

        set<vector<int>> result;
        for (auto it = data.begin();it != data.end();it++) {
            int targetLeft = target - it->first;
            auto searchVectorA = it->second;

            // same
            if (targetLeft == it->first) {
                for (int i=0;i+1< searchVectorA.size();i++) {
                    for (int j=i+1;j<searchVectorA.size();j++) {
                        if (individual(searchVectorA[i], searchVectorA[j])){
                            result.insert(merge(nums, searchVectorA[i], searchVectorA[j]));
                        }
                    }
                }
            }

            if (data.find(targetLeft) != data.end()) {
                auto searchVectorB =  data[targetLeft];
                for (auto i : searchVectorA) {
                    for (auto j : searchVectorB) {
                        if (individual(i, j)) {
                            result.insert(merge(nums, i, j));
                        }
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (auto it : result){
            res.emplace_back(it);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> test= {-3, -2, -1, 0, 0, 1, 2, 3};
    s.fourSum(test, 0);
    cout << "" << endl;
}