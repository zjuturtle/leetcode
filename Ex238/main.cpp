#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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