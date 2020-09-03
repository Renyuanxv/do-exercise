/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* rebuild(vector<int>& preorder, int preRight, int preLeft, vector<int>& inorder, int inoRight, int inoLeft) {
        if (preRight > preLeft || inoRight > inoLeft)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preRight]);
        for (auto i = 0; i <= inoLeft; ++i) {
            if (preorder[preRight] == inorder[i]) {
                root->left = rebuild(preorder, preRight + 1, i - inoRight + preRight, inorder, inoRight, i - 1);
                root->right = rebuild(preorder, i - inoRight + preRight + 1, preLeft, inorder, i + 1, inoLeft);
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        return rebuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};