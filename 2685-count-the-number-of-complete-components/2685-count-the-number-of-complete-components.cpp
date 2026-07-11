class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(auto k:edges){
            int u=k[0];
            int v=k[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         int cnt = 0;
        for(int i=0;i<n;i++){
            int c=0;
            if(!visited[i]){ 
                queue<int>q;
                q.push(i);
                visited[i]=1;
                int vertices = 0;
                int edgeCount = 0;
                while(!q.empty()){
                    int p=q.front();
                    q.pop();
                     vertices++;
                    edgeCount += adj[p].size();
                    for(auto k:adj[p]){
                        if(!visited[k]){ visited[k]=1;
                        q.push(k);
                      }
                    }
                }
                 edgeCount /= 2;
                if (edgeCount == vertices * (vertices - 1) / 2)  cnt++;
            }
        }
        return cnt;
    }
};