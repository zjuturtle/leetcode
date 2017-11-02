#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

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
