// Determine whether an integer is a palindrome. Do this without extra space.
#include <iostream>


using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int countRight = 1;
        int countLeft = 1;
        while (x / countLeft >= 10) countLeft*=10;
        while (true) {
            if (countLeft <= countRight) return true;
            if (x/countLeft%10 != x/countRight%10) return false;
            countLeft /= 10;
            countRight *= 10;
        }
    }
};

int main() {
    Solution s;
    cout <<s.isPalindrome(10021);
    return 0;
}