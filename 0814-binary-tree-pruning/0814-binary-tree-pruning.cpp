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
    bool pratik(TreeNode* root){
        if(root==nullptr) return false;
        bool l=pratik(root->left);
        bool r=pratik(root->right);
        if(l==false) root->left=nullptr;
        if(r==false) root->right=nullptr;
        if(root->val==1) return true;
        return l || r;
    }
    TreeNode* pruneTree(TreeNode* root) {
         if(pratik(root)==false) return nullptr;
        return root;
    }
};