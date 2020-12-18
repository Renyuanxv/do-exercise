# LeecCode 199. 二叉树的右视图

给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:
* 输入:[1,2,3,null,5,null,4]
* 输出:[1, 3, 4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // BFS 
 //时间：O(n)
 //空间: O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> ans;
        vector<int> result;
        if(root!=NULL)
            ans.push(root);
        while(!ans.empty()){
            int size=ans.size();
            for(int i=0;i<size;++i){
                TreeNode* tmp=ans.front();
                ans.pop();
                if(i==size-1)
                    result.push_back(tmp->val);
                if(tmp->left)
                    ans.push(tmp->left);
                if(tmp->right)
                    ans.push(tmp->right);
            }
        }
        return result;
    }
};
```
```cpp
//DFS
//时间：O(n)
//空间：O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(result,root,0);
        return result;

    }
    void dfs(vector<int>& v,TreeNode* root,int depth) {
        if(root==NULL)
            return;
        
        if(depth==v.size())
            v.push_back(root->val);
        depth++;
        dfs(v,root->right,depth);
        dfs(v,root->left,depth);
    }
};
```
