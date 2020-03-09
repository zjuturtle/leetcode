//
// Created by 雷京颢 on 2020/3/7.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    inline bool is0(char in) {
        return in == '0';
    }
    inline bool is1(char in) {
        return in == '1';
    }
    inline bool is2(char in) {
        return in == '2';
    }
    inline bool is12(char in) {
        return '1' <= in && in <= '2';
    }
    inline bool is19(char in) {
        return '1' <= in && in <= '9';
    }
    inline bool is16(char in) {
        return '1' <= in && in <= '6';
    }
    inline bool is79(char in) {
        return '7' <= in && in <= '9';
    }
    inline bool is39(char in) {
        return '3' <= in && in <= '9';
    }
    inline bool is29(char in) {
        return '2' <= in && in <= '9';
    }

    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s[0] == '0')
            return 0;
        vector<int> mem(s.size(), 0);
        if (s.size() == 1) {
            if (is19(s[0])) {
                return 1;
            } else {
                return 0;
            }
        }


        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                mem[0] = 1;
                continue;
            }
            if (is0(s[i]) && is0(s[i-1])) return 0;
            if (is0(s[i]) && is39(s[i-1])) return 0;
            if (i == 1) {
                if (is1(s[i-1]) && is19(s[i])) {
                    mem[1] = 2;
                    continue;
                }
                if (is2(s[i-1]) && is16(s[i])){
                    mem[1] = 2;
                    continue;
                }
                mem[1] = 1;
                continue;
            }

            if (is0(s[i])) {
                mem[i] = mem[i-2];
            }

            if (is16(s[i])) {
                if (is0(s[i-1])) {
                    mem[i] = mem[i-1];
                }
                if (is12(s[i-1])) {
                    mem[i] = mem[i-2] + mem[i-1];
                }
                if (is39(s[i-1])) {
                    mem[i] = mem[i-1];
                }
            }

            if (is79(s[i])) {
                if (is0(s[i-1])) {
                    mem[i] = mem[i-1];
                }
                if (is1(s[i-1])) {
                    mem[i] = mem[i-2] + mem[i-1];
                }
                if (is29(s[i-1])) {
                    mem[i] = mem[i-1];
                }
            }
        }
        return mem[s.size()-1];
    }
};

int main() {
    cout << "" << endl;
}