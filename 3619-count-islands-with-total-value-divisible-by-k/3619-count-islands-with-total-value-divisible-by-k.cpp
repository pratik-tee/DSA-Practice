class Solution {
public:
    bool pratik(vector<vector<int>>&grid,int k,vector<vector<int>>&visited,int i,int j){
        int n=grid.size(),m=grid[0].size();
        int r[]={0,1,0,-1};
        int c[]={1,0,-1,0};
        queue<pair<int,int>>q;
        q.push({i,j});
        long long sum=0;
        while(!q.empty()){
            int ai=q.front().first;
            int aj=q.front().second;
            q.pop();
            sum+=grid[ai][aj];
            for(int p=0;p<4;p++){
                int ni=ai+r[p];
                int nj=aj+c[p];
                if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj] && grid[ni][nj]!=0){
                    q.push({ni,nj});
                    visited[ni][nj]=1;
                }
            }
        }
        return sum%k==0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size(),count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                   visited[i][j]=1;
                   if(pratik(grid,k,visited,i,j)) count++;;
                }
            }
        }
        return count;
    }
};