// Implement regular expression matching with support for '.' and '*'.
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "a*a*b") → true
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string text, string pattern) {
        if (pattern.empty()) return text.empty();
        bool first_match = (!text.empty() &&
                               (pattern[0] == text[0] || pattern[0] == '.'));

        if (pattern.size() >= 2 && pattern[1] == '*'){
            return (isMatch(text, pattern.substr(2, pattern.size())) ||
                    (first_match && isMatch(text.substr(1, text.size()), pattern)));
        } else {
            return first_match && isMatch(text.substr(1, text.size()), pattern.substr(1, pattern.size()));
        }
    }

};

int main() {
    Solution s;
    //cout << s.isMatch("aa", "a*");
    //cout << s.isMatch("aa", ".*");
    cout << s.isMatch("aab", "c*a*b");
}