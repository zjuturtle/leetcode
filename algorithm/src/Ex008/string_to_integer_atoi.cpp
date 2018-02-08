//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//
//spoilers alert... click to show requirements for atoi.

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        string non_empty_str, digit_str;
        for (int i = 0; i < str.size();i++) {
            auto ch = str[i];
            if (ch != ' ') {
                non_empty_str = str.substr(i, str.size()-i);
                break;
            }
        }
        if (non_empty_str.empty())
            return 0;
        bool negative = false;

        switch(non_empty_str[0]) {
            case '-':
                negative = true;
            case '+':
                digit_str = non_empty_str.substr(1, non_empty_str.size()-1);
                break;
            default:
                digit_str = non_empty_str;
        }

        int res = 0;
        for (int i = 0; i < digit_str.size(); i++) {
            int digit = digit_str[i] - '0';
            if (digit < 0 || digit > 9)
                break;
            if (res > 0 &&!negative && res > (INT_MAX - digit)/10) return INT_MAX;
            if (res > 0 &&negative && -res < (INT_MIN + digit)/10) return INT_MIN;
            res = res*10 + digit;
        }
        if (negative)
            return -res;
        else
            return res;
    }
};

int main() {
    Solution s;
    cout<<s.myAtoi("-01324000")<<endl;
    return 0;
}