#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        
        //odd length case
        for (int index = 0; index <= s.size(); index++) {
            int offset = 0;
            while(true) {
                offset++;
                if( index-offset < 0 || index+offset >= s.size())
                    break;
                if( s[index-offset] != s[index+offset])
                    break;
            }
            string tmp = s.substr(index - offset + 1 , 2*offset - 1);
            if(tmp.size() > res.size())
                res = tmp;
        }
        
        //even length case
        for (int index = 0; index <= s.size(); index++) {
            int offset = -1;
            while(true){
                offset++;
                if( index-offset < 0 || index+offset+1 >= s.size())
                    break;
                if( s[index-offset] != s[index+offset+1])
                    break;
            }
            if (0 == offset)
                continue;
            string tmp = s.substr(index - offset + 1, 2*offset);
            if(tmp.size() > res.size())
                res = tmp;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.longestPalindrome("cbbc")<<endl;
    return 0;
}
