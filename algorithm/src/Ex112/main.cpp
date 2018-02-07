//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
//return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (nullptr == root) return false;
        return hasPath(root, sum);
    }

    bool hasPath(TreeNode* root, int sum){
        if (nullptr == root->left && nullptr == root->right){
            if (root->val == sum) return true;
            else return false;
        }
        if (hasPathSum(root->left, sum-root->val)) return true;
        if (hasPathSum(root->right, sum-root->val)) return true;
        return false;
    }
};

int main() {
    return 0;
}
