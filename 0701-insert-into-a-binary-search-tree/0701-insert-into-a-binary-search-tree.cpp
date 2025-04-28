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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* r;
        if(root==NULL){
           r=new TreeNode;
           r->val=val;
           r->left=NULL;
           r->right=NULL;
           return r;
        }
        if(val<root->val)
            root->left=insertIntoBST(root->left,val);
        else if(val>root->val)
            root->right=insertIntoBST(root->right,val);
        return root;

    }
};