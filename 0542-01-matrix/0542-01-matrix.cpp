class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>>q;
        
        int m=mat.size(),n=mat[0].size();
            vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    q.push({0,{i,j}});
                    visited[i][j]=1;
                }
           }
        }
        vector<vector<int>>ans=mat;
    
        int rowd[]={0,-1,0,1};
        int cold[]={-1,0,1,0};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.second.first;
            int j=p.second.second;
            int d=p.first;
            for(int k=0;k<4;k++){
                int ni=i+rowd[k];
                int nj=j+cold[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj] && mat[ni][nj]==1){
                    visited[ni][nj]=1;
                    q.push({d+1,{ni,nj}});
                    ans[ni][nj]=d+1;
                }
            }
        }
        return ans;
    }
};