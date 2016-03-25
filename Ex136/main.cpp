#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto it = nums.begin(); it != nums.end(); it++) {
			res ^= *it;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1, 0, 1 };
	cout << s.singleNumber(a);
	getchar();
	return 0;
}