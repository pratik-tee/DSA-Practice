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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        vector<vector<int>>ans;
        if(root==nullptr) return {};
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>temp(n);
            for(int i=0;i<n;i++){
                TreeNode *FrontNode=q.front();
                q.pop();
                temp[i]=FrontNode->val;
                if(FrontNode->left) q.push(FrontNode->left);
                 if(FrontNode->right) q.push(FrontNode->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};