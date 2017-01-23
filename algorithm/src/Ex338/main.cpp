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