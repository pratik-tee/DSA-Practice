class Solution {
public:
    int pratik(string& s,string& t,int n,int m,int i,int j,vector<vector<int>>&dp){
         if(j==m) return 1;
         if(i>=n) return 0;
         if(dp[i][j]!=-1) return dp[i][j];
         int take=0;
         if(s[i]==t[j]) take=pratik(s,t,n,m,i+1,j+1,dp);
         int not_take=pratik(s,t,n,m,i+1,j,dp);
         return dp[i][j]=take+not_take;

    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return pratik(s,t,n,m,0,0,dp);
    }
};