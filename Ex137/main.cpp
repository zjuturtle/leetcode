#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> positiveCounts(32, 0);
		vector<int> negtiveCounts(32, 0);
		for (auto it = nums.begin(); it != nums.end(); it++) {
			auto tmp = *it;
			int index = 0;
			if (tmp > 0) {
				while (tmp!=0) {
					positiveCounts[index] += (tmp % 2);
					tmp /= 2;
					index++;		
				}
			}
			else {
				tmp = -tmp;
				while (tmp != 0) {
					negtiveCounts[index] += (tmp % 2);
					tmp /= 2;
					index++;
				}
			}
		}
		int pos = 0,neg=0,p=1,n=1;
		for (int i = 0; i < 32; i++) {
			auto pbit = positiveCounts[i] %= 3;
			auto nbit = negtiveCounts[i] %= 3;
			pos += (pbit*p);
			neg += (nbit*n);
			p *= 2;
			n *= 2;
		}
		if(pos>0)
			return pos;
		return -neg;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1, 1,-3, 1,2,2,2 };
	cout << s.singleNumber(a);
	getchar();
	return 0;
}