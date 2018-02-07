//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include<iostream>

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
