//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the
// "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that
// "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked
// houses were broken into on the same night.
//
//Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
// Example 1:
//     3
//    / \
//   2   3
//    \   \
//     3   1
//Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:
//     3
//    / \
//   4   5
//  / \   \
// 1   3   1
//Maximum amount of money the thief can rob = 4 + 5 = 9.

#include<iostream>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	struct Money {
		int pre;  //not rob this node
		int curr; //rob this node
		explicit Money() :pre(0), curr(0) {}
	};

	int rob(TreeNode* root) {
		Money sum = dfs(root);
		return sum.curr;
	}

	Money dfs(TreeNode* root)
	{
		if (root == nullptr) return Money();
		Money leftMoney = dfs(root->left);   
		Money rightMoney = dfs(root->right); 
		Money sumMoney;
		sumMoney.pre = leftMoney.curr + rightMoney.curr; // not rob this node
		sumMoney.curr = max(sumMoney.pre, root->val + leftMoney.pre + rightMoney.pre);
		return sumMoney;
	}
};

int main() {

	getchar();
}