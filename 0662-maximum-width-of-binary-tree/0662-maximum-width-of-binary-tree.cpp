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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
       queue<pair<TreeNode*,long long>>q;
       long long mw=0;
       q.push({root,0});
       while(!q.empty()){
          int n=q.size();
          long long m=q.front().second;
          long long f=0,l=0;
          for(int i=0;i<n;i++){
              TreeNode* fr=q.front().first;
              long long curr=q.front().second-m;
              q.pop();
              if(i==0) f=curr;
              if(i==n-1) l=curr;
              if(fr->left!=nullptr) q.push({fr->left,curr*2+1});
              if(fr->right!=nullptr) q.push({fr->right,curr*2+2});
          }
          mw=max(mw,l-f+1);
       }
       return (int)mw;
    }
};