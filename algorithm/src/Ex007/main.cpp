//Given a 32-bit signed integer, reverse digits of an integer.
//
//Example 1:
//
//Input: 123
//Output:  321
//Example 2:
//
//Input: -123
//Output: -321
//Example 3:
//
//Input: 120
//Output: 21
//Note: Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer
//      range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negtive = x < 0;
        x = abs(x);
        vector<int> re;
        do {
            re.emplace_back(x%10);
            x/=10;
        } while(x != 0);

        unsigned long res = 0;
        for (auto it = re.cbegin(); it != re.cend(); it++)
            res = res*10 + *it;
        if (res > 2147483647)
            return 0;
        else
            return negtive ? -res : res;
    }
};

int main() {
    Solution s;
    cout<<s.reverse(-321)<<endl;
    return 0;
}
