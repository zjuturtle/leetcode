//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Example 1:
//Input: [7, 1, 5, 3, 6, 4]
//Output: 5
//
//max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
//Example 2:
//Input: [7, 6, 4, 3, 1]
//Output: 0
//
//In this case, no transaction is done, i.e. max profit = 0.

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