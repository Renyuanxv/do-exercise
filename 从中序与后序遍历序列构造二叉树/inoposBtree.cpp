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
    TreeNode* rebuild(vector<int>& inorder, int inoLeft, int inoRight, vector<int>& postorder, int posLeft, int posRight) {
        if (inoLeft > inoRight || posLeft > posRight)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[posRight]);
        for (auto i = 0; i <= inoRight; ++i) {
            if (inorder[i] == postorder[posRight]) {
                root->left = rebuild(inorder, inoLeft, i - 1, postorder, posLeft, i - inoLeft + posLeft - 1);
                root->right = rebuild(inorder, i + 1, inoRight, postorder, i - inoLeft + posLeft, posRight - 1);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return nullptr;
        return rebuild(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};