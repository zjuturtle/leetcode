//
// Created by 雷京颢 on 2020/3/14.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Solution {
public:

    bool addOne(vector<int> &currentNum, const vector<int> &limit) {
        currentNum[0]++;
        for (int i=0;i<currentNum.size();i++) {
            if (currentNum[i] < limit[i]) {
                return false;
            }
            if (currentNum[i] == limit[i] && i == currentNum.size() - 1) {
                return true;
            }
            if (currentNum[i] == limit[i]) {
                currentNum[i] = 0;
                currentNum[i+1]++;
            }
        }
        return false;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        map<char, string> data;
        data['2'] = "abc";
        data['3'] = "def";
        data['4'] = "ghi";
        data['5'] = "jkl";
        data['6'] = "mno";
        data['7'] = "pqrs";
        data['8'] = "tuv";
        data['9'] = "wxyz";

        vector<int> limit;
        vector<int> currentNum(digits.size(), 0);
        for (char digit : digits) {
            limit.emplace_back(data[digit].size());
        }


        while(true) {
            string res;
            res.reserve(digits.size());
            for (int i=0;i<currentNum.size();i++){
                res.push_back( data[digits[i]][currentNum[i]] );
            }
            result.emplace_back(res);
            if (addOne(currentNum, limit)){
                break;
            }
        }

        return result;
    }
};
int main(){
    cout << "" << endl;
}