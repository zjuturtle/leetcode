#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> m;
		for (auto it = strs.begin(); it != strs.end(); it++) {
			m[getCode(*it)].push_back(*it);
		}
		vector<vector<string>> res;
		for (auto it = m.begin(); it != m.end(); it++) {
			sort((*it).second.begin(), (*it).second.end());
			res.push_back((*it).second);
		}
		return res;
	}
	string getCode(string s) {
		sort(s.begin(), s.end());
		return s;
	}
};
int main() {
	getchar();
	return 0;
}