#include<iostream>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (1 == m || 1 == n)
			return 1;
		int **pMatrix = new int*[n];
		for (int i = 0; i < n; i++)
			pMatrix[i] = new int[m];
		for (int i = 0; i < n; i++)
			pMatrix[i][0] = 1;
		for (int i = 0; i < m; i++)
			pMatrix[0][i] = 1;

		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j) {
				pMatrix[j][i] = pMatrix[j-1][i]+ pMatrix[j][i - 1];
			}
		return pMatrix[n-1][m-1];
	}
};
int main() {
	Solution s;
	cout << s.uniquePaths(6,4);
	getchar();
	return 0;
}