class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),m=isConnected[0].size();
        vector<vector<int>>adj(n);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
              if(isConnected[i][j]==1 && i!=j) adj[i].push_back(j); 
        }
       } 
        vector<int>visited(n,0);
      int count=0;
       
       
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int>temp;
                 stack<int>st;
                 st.push(i);
                 visited[i]=1;
                while(!st.empty()){
                   int t=st.top();
                    st.pop();
                    visited[t]=1;
                  for(int i=0;i<adj[t].size() ;i++){
                       int k=adj[t][i];
                       if(!visited[k]){
                               st.push(k);
                               visited[k]=1;
                           }
                  }
               }
               count++;
            }  
            
        }
        return count;
    }
};