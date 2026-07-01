class Solution {
public:
    vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};

    bool isValid(vector<vector<int>>&dist,int sf){
        int n=dist.size();
        if(dist[0][0]<sf ||dist[n-1][n-1] <sf) return false;
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        q.push({0,0});
        visited[0][0]=1;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i==n-1 && j==n-1) return true;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n && !visited[ni][nj] && dist[ni][nj]>=sf){
                    visited[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
        }
        return false;
    } 




    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        vector<vector<int>>dist(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int len=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n && !visited[ni][nj]){
                    q.push({ni,nj});
                    visited[ni][nj]=1;
                    dist[ni][nj]=dist[i][j]+1;
                    len=max(dist[ni][nj],len);
                }
            }
        }
        int l=0,h=len,ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(isValid(dist,mid)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};