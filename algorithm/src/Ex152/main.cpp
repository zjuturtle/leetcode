#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (1 == nums.size())
			return nums[0];
		int max = 0;
		vector<int> zeroIndex;
		for (int i = 0; i < nums.size(); i++) {
			if (0 == nums[i])
				zeroIndex.push_back(i);
		}
		vector<pair<int, int>> trunc;
		int last = 0;
		for (auto it = zeroIndex.begin(); it != zeroIndex.end(); it++) {		
			trunc.push_back(make_pair(last,*it));	
			last = *it + 1;
		}
		if (last != nums.size())
			trunc.push_back(make_pair(last,nums.size()));

		for (auto it = trunc.begin(); it != trunc.end(); it++) {
			auto tmp = maxProduct(nums,(*it).first,(*it).second);
			if (tmp > max)
				max = tmp;
		}
		return max;
	}

	int maxProduct(vector<int>& nums, int startIndex, int endIndex) {
		if (startIndex == endIndex)
			return 0;
		if (startIndex == endIndex + 1)
			return nums[0];
		int firstNegtiveIndex = -1, lastNegtiveIndex = -1,negNum = 0;
		for (int i = startIndex; i < endIndex; i++) {
			if (nums[i] < 0) {
				negNum++;
			}
		}
		for (int i = startIndex; i < endIndex; i++) {
			if (nums[i] < 0 ) {
				firstNegtiveIndex = i;
				break;
			}
		}
		for (int i = endIndex-1; i != startIndex; i--) {
			if (nums[i] < 0) {
				lastNegtiveIndex = i;
				break;
			}
		}
		if (-1 == firstNegtiveIndex || negNum%2==0) {
			int res = 1;
			for (int i = startIndex; i < endIndex; i++) {
				res *= nums[i];
			}
			return res;
		}

		int leftMax = 1, rightMax = 1;
		bool left = false;
		bool right = false;
		for (int i = firstNegtiveIndex + 1; i < endIndex; i++) {
			left = true;
			leftMax *= nums[i];
		}
		for (int i =  startIndex; i < lastNegtiveIndex; i++) {
			right = true;
			rightMax *= nums[i];
		}

		if (!left)
			leftMax = 0;

		if (!right)
			rightMax = 0;

		return leftMax > rightMax ? leftMax : rightMax;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1,3,1,0,-2,-9 };
	auto t = s.maxProduct(a);
	cout << t;
	getchar();
	return 0;
}