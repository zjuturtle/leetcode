//
// Created by 雷京颢 on 2020/3/7.
//
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string result = "";
        int minSize = INT_MAX;
        for (auto &it : strs) {
            if (minSize > it.size())
                minSize = it.size();
        }
        if (minSize == 0) {
            return "";
        }

        int index = 0;
        while(true) {
            if (index == minSize) {
                return result;
            }
            char check = strs[0][index];
            for (auto &it : strs) {
                if (it[index] != check) {
                    return result;
                }
            }
            result.push_back(check);
            index++;
        }
    }
};

int main() {
    Solution s;
    cout << "s.longestCommonPrefix()" << endl;
}