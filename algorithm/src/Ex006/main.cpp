#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        res.assign(' ', s.size());
        for (int index = 0;index < s.size();index+=numRows) {
            for (int offset = 0;offset <numRows;offset+=1)
                res[index+offset]=;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.convert("PAYPALISHIRING", 3)<<endl;
    return 0;
}
