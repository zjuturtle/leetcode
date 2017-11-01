#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string res;
        int index = 0;
        int currentRow = 0;
        int nextIndexOffset = 2*(numRows - currentRow - 1);
        bool downFlag = true;
        while (true) {
            if (res.size() == s.size())
                break;
            res.push_back(s[index]);
            if (downFlag)
                nextIndexOffset = 2*(numRows - currentRow - 1);
            else
                nextIndexOffset = 2*currentRow;
            downFlag = !downFlag;
            if (nextIndexOffset == 0)
                nextIndexOffset = max(2*(numRows - currentRow - 1), 2*currentRow);
            index += nextIndexOffset;
            if (index >= s.size()) {
                index = ++currentRow;
                downFlag = true;
                continue;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.convert("AB", 3)<<endl;
    return 0;
}
