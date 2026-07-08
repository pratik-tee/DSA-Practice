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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        int k=0;
        if(root==nullptr) return {};
        while(!q.empty()){
            int n=q.size();
            vector<int>temp(n);
            k=!k;
            for(int i=0;i<n;i++){
                TreeNode *t=q.front();
                q.pop();
                if(k==1) temp[i]=t->val;
                else  temp[n-i-1]=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};