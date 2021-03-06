// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear
// exactly twice. Find the two elements that appear only once.
//
// For example:
//
// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//
// Note:
//	  The order of the result is not important. So in the above example, [5, 3] is also correct.
//    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int tmp=0,tmp1=1,numA=0,numB=0;
		for (auto it = nums.begin(); it != nums.end(); it++) {
			tmp ^= (*it);
		}
		while (tmp % 2 == 0) {
			tmp1 *= 2;
			tmp /= 2;
		}

		for (auto it = nums.begin(); it != nums.end(); it++) {
			if ((tmp1 ^ (*it)) == ((*it)-tmp1)) {
				numA ^= (*it);
			}
			else {
				numB ^= (*it);
			}
		}
		auto res = new vector<int>;
		(*res).push_back(numA);
		(*res).push_back(numB);
		return *res;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1,3, 1,2,2,5 };
	auto t = s.singleNumber(a);
	cout << t[0]<<" "<<t[1];
	getchar();
	return 0;
}