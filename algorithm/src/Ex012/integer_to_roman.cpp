//
// Created by 雷京颢 on 2020/3/7.
//
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    map<int,string> dataMap;
    vector<int> dataVec;
    string intToRoman(int num) {
        dataMap[1] = "I";
        dataMap[4] = "IV";
        dataMap[5] = "V";
        dataMap[9] = "IX";
        dataMap[10] = "X";
        dataMap[40] = "XL";
        dataMap[50] = "L";
        dataMap[90] = "XC";
        dataMap[100] = "C";
        dataMap[400] = "CD";
        dataMap[500] = "D";
        dataMap[900] = "CM";
        dataMap[1000] = "M";
        dataVec = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        return intToRomanInner(num);
    }

    string intToRomanInner(int num) {
        string result;
        while(num) {
            for (int i=0;i<dataVec.size();i++) {
                if (dataVec[i] <= num) {
                    result.append(dataMap[dataVec[i]]);
                    num -= dataVec[i];
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(1994) << endl;
}