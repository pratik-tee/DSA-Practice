class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
         vector<int>ind(n,0);
         queue<int>q;
         vector<int>ans;
         vector<vector<int>>adj(n);
         for(int i=0;i<n;i++){
             for(auto e:graph[i]){
                 adj[e].push_back(i);
                 ind[i]++;
             }
         }
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            auto e=q.front();
            q.pop();
            ans.push_back(e);
            for(auto k:adj[e]){
                ind[k]--;
                if(ind[k]==0) q.push(k);
            }
        }
        
       sort(ans.begin(),ans.end());
       return ans;
    }
};