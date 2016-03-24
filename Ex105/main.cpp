//http://blog.csdn.net/sbitswc/article/details/26433051
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0)
			return NULL;
		return build(inorder, postorder, 0, inorder.size(),0, postorder.size());
	}

	TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
		if (inStart == inEnd)
			return NULL;
		 auto res = new TreeNode(postorder[postEnd-1]);
		 int len = 0;
		 for (int i = inStart; i < inEnd; i++) {
			 if (inorder[i] == (*res).val) {
				 len = i - inStart;
				 break;
			 }
		 }
		 (*res).left = build(inorder, postorder, inStart, inStart +len,postStart,postStart+len);
		 (*res).right = build(inorder, postorder, inStart + len + 1,inEnd, postStart+len,postEnd-1 );
		 return res;
	}

	//for test
	void postorder(TreeNode* t) {
		if (t != NULL) {
			postorder((*t).left);
			postorder((*t).right);
			cout << (*t).val << " ";
		}
		else {
			return;
		}
	}

	void inorder(TreeNode* t) {
		if (t != NULL) {		
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

	int preorder[] = {4,1,3,2};
	int inorder[] = { 1,2,3,4 };
	size_t count = sizeof(preorder) / sizeof(int);
	vector<int> pre(preorder, preorder + count);
	vector<int> in(inorder, inorder + count);
	Solution s;
	auto t=s.buildTree(pre,in);
	s.postorder(t);
	cout << endl;
	s.inorder(t);
	getchar();
}