#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> path;
		if (NULL == root)
			return res;
		pathSum(root, path, sum);
		return res;
	}
	void pathSum(TreeNode* root, vector<int> path,int sum) {
		path.push_back((*root).val);
		if ((*root).val == sum && (*root).left == NULL && (*root).right == NULL) {
			res.push_back(path);
			return;
		}
		if ((*root).left != NULL) {
			pathSum((*root).left, path,sum-(*root).val);
		}
		if ((*root).right != NULL) {
			pathSum((*root).right, path, sum - (*root).val);
		}
	}
};