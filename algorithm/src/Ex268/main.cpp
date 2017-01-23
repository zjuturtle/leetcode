#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sumOfNums = 0;
		for (auto it = nums.begin(); it != nums.end(); it++)
			sumOfNums += *it;
		int expected = (1 + nums.size())*nums.size() / 2;
		return expected - sumOfNums;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1, 0, 3 };
	cout << s.missingNumber(a);
	getchar();
	return 0;
}