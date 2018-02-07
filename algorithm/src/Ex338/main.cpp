//Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in
// their binary representation and return them as an array.
//
//Example:
//		For num = 5 you should return [0,1,1,2,1,2].
//
//Follow up:
//
//It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time
// O(n) /possibly in a single pass?
//Space complexity should be O(n).
//Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res;
		res.push_back(0);
		if (num == 0) {
			return res;
		}
		res.push_back(1);
		if (num == 1) {
			return res;
		}
		while (true) {
			int size = res.size();
			for (int i = 0; i < size; i++) {
				res.push_back(res[i] + 1);
				if (res.size() == num + 1) {
					return res;
				}
			}
		}
	}
};
int main() {
	Solution s;
	vector<int> res = s.countBits(5);
	for (auto it = res.begin(); it != res.end(); ++it)
		cout << (*it) << endl;
	getchar();
	return 0;
}