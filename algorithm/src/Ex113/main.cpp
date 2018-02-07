//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//return
// [
//   [5,4,11,2],
//   [5,8,4,5]
// ]

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> path;
		if (nullptr == root)
			return res;
		pathSum(root, path, sum);
		return res;
	}
	void pathSum(TreeNode* root, vector<int> path,int sum) {
		path.push_back((*root).val);
		if ((*root).val == sum && (*root).left == nullptr && (*root).right == nullptr) {
			res.push_back(path);
			return;
		}
		if ((*root).left != nullptr) {
			pathSum((*root).left, path,sum-(*root).val);
		}
		if ((*root).right != nullptr) {
			pathSum((*root).right, path, sum - (*root).val);
		}
	}
};

int main() {
	return 0;
}