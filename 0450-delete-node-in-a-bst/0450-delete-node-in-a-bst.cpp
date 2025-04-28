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
    int Height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = Height(root->left);
        int right = Height(root->right);
        return max(left,right)+1;
    }
    TreeNode* InPre(TreeNode* p){
        while(p&&p->right!=NULL){
           p=p->right; 
        }
        return p;
    }
    TreeNode* InSucc(TreeNode* p){
         while(p&&p->left!=NULL){
           p=p->left; 
        }
        return p;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*q;
        if(root==NULL){
            return NULL;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }else if(key>root->val){
            root->right=deleteNode(root->right,key);
        } else{
             if(root->right==NULL && root->left==NULL){
            delete(root);
            return NULL;
        }else if(root->left&&root->right){
            if(Height(root->left)>Height(root->right)){
                q=InPre(root->left);
                root->val=q->val;
                root->left=deleteNode(root->left,q->val);
            }else{
                q=InSucc(root->right);
                root->val=q->val;
                root->right=deleteNode(root->right,q->val);
            }
        }
        }
        return root;
    }
};