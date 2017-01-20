#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string res = "";
        string tempStr = "";
        unordered_set<char> tmp;
        for (auto it = s.cbegin(); it != s.cend(); it++) {
            if(tmp.find(*it) == tmp.end()){
                tmp.insert(*it);
            } else {
                string tmpS;
                tmpS = string(tempStr, tempStr.find(*it)+1);
                tempStr = tmpS;
            }
            tempStr.push_back(*it);
            if (tempStr.size() > res.size())
                res = tempStr;
        }
        return res.size();
    }
};

int main() {
    Solution s;
    s.lengthOfLongestSubstring("abcabcbb");
    getchar();
    return 0;
}
