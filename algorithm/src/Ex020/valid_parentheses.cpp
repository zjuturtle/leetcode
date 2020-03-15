//
// Created by 雷京颢 on 2020/3/15.
//
#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char ch : s) {
            if ('(' == ch || '[' == ch || '{' == ch) stack.push(ch);
            if (stack.empty()) return false;
            if (')' == ch) {
                if ('(' != stack.top()) {
                    return false;
                }
                stack.pop();
            }
            if (']' == ch) {
                if ('[' != stack.top()) {
                    return false;
                }
                stack.pop();
            }
            if ('}' == ch) {
                if ('{' != stack.top()) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};

int main(){
    cout << "" << endl;
}