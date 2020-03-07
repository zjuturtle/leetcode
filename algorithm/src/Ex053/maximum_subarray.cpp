//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//		the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//


#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int maxSubArray(const vector<int>& nums) {
		int result(0);
		if (nums.size() > 0) {
			result = nums[0];
			int max_ending_here(nums[0]);
			if (nums.size() > 1) {
				for (size_t i = 1; i < nums.size(); ++i) {
					max_ending_here = max(max_ending_here + nums[i], nums[i]);
					result = max(max_ending_here, result);
				}
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> a = { -9,-2,1,8,7,-6,4,9,-9,-5,0,5,-2,5,9,7 };
	auto t = s.maxSubArray(a);
	cout << t <<"end";
	system("pause");
	return 0;
}