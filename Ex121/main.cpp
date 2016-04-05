#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int min = 99999;
		int max = 0;
		for (auto it = prices.begin(); it != prices.end(); it++) {
			max = max < (*it - min) ? (*it - min) : max;
			if (*it < min) {
				min = *it;
			}
		}
		return max;
	}
};

int main() {
	Solution s;
	vector<int> a = { -9,-2,1,8,7,-6,4,9,-9,-5,0,5,-2,5,9,7 };
	cout<<s.maxProfit(a);
	system("pause");
	return 0;
}