// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you
// like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in
// multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		for (int i = 0; i < prices.size();i++) {
			while (i+1<prices.size() && prices[i] > prices[i + 1])
				i++;
			int buy = prices[i];
			while (i +1< prices.size() && prices[i] < prices[i + 1])
				i++;
			int sell = prices[i];
			profit += (sell - buy);
		}
		return profit;
	}
};

int main() {
	Solution s;
	vector<int> a = { 2,1};
	cout << s.maxProfit(a);
	system("pause");
	return 0;
}