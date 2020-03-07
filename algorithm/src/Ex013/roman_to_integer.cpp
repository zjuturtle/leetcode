//
// Created by 雷京颢 on 2020/3/7.
//
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> dataMap;
        dataMap["I"] = 1;
        dataMap["IV"] = 4;
        dataMap["V"] = 5;
        dataMap["IX"] = 9;
        dataMap["X"] = 10;
        dataMap["XL"] = 40;
        dataMap["L"] = 50;
        dataMap["XC"] = 90;
        dataMap["C"] = 100;
        dataMap["CD"] = 400;
        dataMap["D"] = 500;
        dataMap["CM"] = 900;
        dataMap["M"] = 1000;
        int result = 0;
        for (int i=0;i<s.size();) {
            string tmp = s.substr(i, 2);
            if(dataMap.find(tmp) != dataMap.end()) {
                result += dataMap[tmp];
                i+=2;
                continue;
            }
            tmp = s.substr(i, 1);
            result += dataMap[tmp];
            i+=1;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("XX") << endl;
}