#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	struct Money {
		int pre;  //not rob this node
		int curr; //rob this node
		Money() :pre(0), curr(0) {}
	};

	int rob(TreeNode* root) {
		Money sum = dfs(root);
		return sum.curr;
	}

	Money dfs(TreeNode* root)
	{
		if (root == NULL) return Money();
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