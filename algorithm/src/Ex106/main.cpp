//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//		You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9,3,15,20,7]
//postorder = [9,15,7,20,3]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7

#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return nullptr;
		return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
	}

	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
		if (preStart == preEnd)
			return nullptr;
		auto res = new TreeNode(preorder[preStart]);
		int len = 0;
		for (int i = inStart; i < inEnd; i++) {
			if (inorder[i] == (*res).val) {
				len = i - inStart;
				break;
			}
		}
		(*res).left = build(preorder, inorder, preStart + 1, preStart + len + 1, inStart, inStart + len);
		(*res).right = build(preorder, inorder, preStart + len + 1, preEnd, inStart + len + 1, inEnd);
		return res;
	}

	//for test
	void preorder(TreeNode* t) {
		if (t != nullptr) {
			cout << (*t).val << " ";
			preorder((*t).left);
			preorder((*t).right);
		}
		else {
			return;
		}
	}

	void inorder(TreeNode* t) {
		if (t != nullptr) {
			inorder((*t).left);
			cout << (*t).val << " ";
			inorder((*t).right);
		}
		else {
			return;
		}
	}
};

int main() {

	int preorder[] = { 4,1,3,2 };
	int inorder[] = { 1,2,3,4 };
	size_t count = sizeof(preorder) / sizeof(int);
	vector<int> pre(preorder, preorder + count);
	vector<int> in(inorder, inorder + count);
	Solution s;
	auto t = s.buildTree(pre, in);
	s.preorder(t);
	cout << endl;
	s.inorder(t);
	getchar();
}