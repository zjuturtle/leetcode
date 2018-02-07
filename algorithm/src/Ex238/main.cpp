// Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the
// product of all the elements of nums except nums[i].
//
// Solve it without division and in O(n).
//
// For example, given [1,2,3,4], return [24,12,8,6].
//
// Follow up:
// Could you solve it with constant space complexity? (Note: The output array does not count as extra space for
// the purpose of space complexity analysis.)

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> f(nums.size()+2,0), b(nums.size()+2,0);
		f[0] = 1;
		f[1] = nums[0];
		b[nums.size()+1] = 1;
		b[nums.size()] = *(nums.end() - 1);
		for (int i = 0; i < nums.size(); i++) {
			f[i+1] = f[i] * nums[i];
			b[nums.size() - i] = nums[nums.size() - i-1]* b[nums.size() - i+1];
		}
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			res.push_back(f[i]*b[i+2]);
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1,3,1,2,2,5 };
	auto t = s.productExceptSelf(a);

	cout << t[0] << " " << t[1];
	getchar();
	return 0;
}