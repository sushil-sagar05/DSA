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
    bool isSame(TreeNode* root,TreeNode* subRoot){
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root==NULL || subRoot==NULL){
            return false;
        }
        if(root->val!=subRoot->val){
            return false;
        }
       if (isSame(root->left,subRoot->left)&& isSame(root->right,subRoot->right)){
        return true;
       }
       return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(root==NULL) return false;
       if(isSame(root,subRoot))return true;
       if(isSame(root->left,subRoot)|| isSame(root->right,subRoot)){
        return true;
       }
       return false;
    }
};