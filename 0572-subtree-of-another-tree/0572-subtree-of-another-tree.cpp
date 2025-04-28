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
    string traverse(TreeNode* root){
        if(root==NULL){
            return "#";
        }
        string st;
        st.append(to_string(root->val));
        st.append(",");
        st.append(traverse(root->left));
        st.append(traverse(root->right));
        return st;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      string FullTree=traverse(root);
      string SubTree=traverse(subRoot);
     return FullTree.find(SubTree) != string::npos;
    }    
};