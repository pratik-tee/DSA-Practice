class Solution {
public:
    bool check(int start,vector<vector<int>>& graph,vector<int>&visited){
         int n=graph.size();
        queue<int>q;
        q.push(start);
        visited[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(visited[it]==-1){
                    visited[it]=!visited[node];
                    q.push(it);
                }
                else if(visited[it]==visited[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
              if(check(i,graph,visited)==false) return false;
            }
        }
        return true;
    }
};