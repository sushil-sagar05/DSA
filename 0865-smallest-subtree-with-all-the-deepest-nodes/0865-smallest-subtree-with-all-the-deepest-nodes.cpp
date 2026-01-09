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
    int maxi;
    int maxDepth(TreeNode *root){
        if(root == NULL) return 0;
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        return 1+max(leftDepth,rightDepth);
    }
    TreeNode* dfs(TreeNode* root,int currLength) {
       if(root ==NULL) return NULL;
       if(currLength==maxi-1) return root;
       TreeNode* left=dfs(root->left,currLength+1);
       TreeNode* right=dfs(root->right,currLength+1);
        if(left && right) return root;
        return left?left:right;

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       maxi=maxDepth(root);
       return dfs(root,0);

    }
};