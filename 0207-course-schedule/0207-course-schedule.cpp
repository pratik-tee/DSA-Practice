class Solution {
public:
    bool dfs(vector<int>&visit,vector<int>&pathvisit,int start ,vector<vector<int>>&adj){
        visit[start]=1;
        pathvisit[start]=1;
        for(auto it:adj[start]){
            if(!visit[it]){
                if(dfs(visit,pathvisit,it,adj)==true) return true;
            }
            else if(pathvisit[it]) return true;
        }
        pathvisit[start]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto e:prerequisites){
            int u=e[0],v=e[1];
            adj[v].push_back(u);
        }
        vector<int>visit(n,0);
        vector<int>pathvisit(n,0);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                if(dfs(visit,pathvisit,i,adj)==true) return false;
            }
        }
        return true;
    }
};