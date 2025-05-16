/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left = dfs(root->left);
        pair<int,int>  right=dfs(root->right);
        int withRoot = root->val + left.second + right.second;
        int withoutRoot = max(left.first, left.second) + max(right.first, right.second);
        return {withRoot,withoutRoot};
    }
    int rob(TreeNode* root) {
        pair<int,int> result= dfs(root);
        return max(result.first,result.second);

    }
};