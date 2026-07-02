class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
         vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
         dist[0][0]=grid[0][0];
         pq.push({grid[0][0],{0,0}});
         
         
         vector<int>dx={0,1,0,-1};
         vector<int>dy={1,0,-1,0};
         while(!pq.empty()){
             int l=pq.top().first;
             int i=pq.top().second.first;
             int j=pq.top().second.second;
             pq.pop();
             if(l > dist[i][j])  continue;

             if(i==m-1 && j==n-1) return l<health;

             for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n   ){
                    int nc=l+grid[ni][nj];
                    if(nc < dist[ni][nj]){
                        dist[ni][nj]=nc;
                        pq.push({nc,{ni,nj}});
                    }
                }
            }
         }
         return false;
    }
};