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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> result;
        if (root != NULL)
            result.push(root);
        while (!result.empty()) {
            TreeNode* node = result.front();
            result.pop();

            TreeNode* temp = node->right;
            node->right = node->left;
            node->left = temp;

            if (node->left)
                result.push(node->left);
            if (node->right)
                result.push(node->right);
        }
        return root;
    }
};