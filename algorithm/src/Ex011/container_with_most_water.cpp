//
// Created by 雷京颢 on 2020/3/7.
//
#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int start = 0; start < height.size()-1; start++) {
            for (int end = start + 1; end < height.size(); end++) {
                int tmp = (end-start)*min(height[start], height[end]);
                max = tmp > max ? tmp : max;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    cout << 'a' << endl;
}