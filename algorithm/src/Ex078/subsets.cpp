//Given a set of distinct integers, nums, return all possible subsets (the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//		If nums = [1,2,3], a solution is:
//
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		deque<int> nu;
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			nu.push_back(*it);
		}
		return  subsets(nu);
	}
	vector<vector<int>> subsets(deque<int> &nums) {
		
		auto res = new vector<vector<int>>;
		if (nums.size()==0) {
			(*res).push_back(*(new vector<int>));
			return *res;
		}
		auto partA = new vector<int>;
		auto tmp = nums[0];
		nums.pop_front();
		auto partB = subsets(nums);
		for (auto it = partB.begin(); it != partB.end(); it++) {
			(*res).push_back(*it);
			auto temp = new vector<int>;
			bool flag = true;
			for (auto itt = (*it).begin(); itt != (*it).end(); ++itt) {
				
				if (tmp < (*itt) && flag) {
					(*temp).push_back(tmp);
					flag = false;
				}
				(*temp).push_back(*itt);
			}
			if (flag) {
				(*temp).push_back(tmp);
			}
			
			(*res).push_back(*temp);
		}
		return *res;
	}
};
int main() {
	vector<int> t = {1,2,3};
	Solution s;
	auto res = s.subsets(t);
	for (auto it = res.begin(); it != res.end(); ++it) {
		cout << "[";
		for (auto itt = (*it).begin(); itt != (*it).end(); ++itt) {
			cout << (*itt) << " ";
		}
		cout <<"]"<< endl;
	}
	getchar();
}