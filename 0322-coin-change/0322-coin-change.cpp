class Solution {
public:
    // int pratik(vector<int>&coins,int sum,int i,int n,vector<vector<int>>&dp){
    //     if(sum==0) return 0;
    //     if(i==n || sum<0) return 1e9;
        
    //     if(dp[i][sum]!=-1) return dp[i][sum];
    //     int take=1+pratik(coins,sum-coins[i],i,n,dp);
    //     int not_take=pratik(coins,sum,i+1,n,dp);
    //     return dp[i][sum]=min(take,not_take);
    // }
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,1e9));

         for(int i=0;i<=n;i++) dp[i][0]=0;
         
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=sum;j++){
               int take = 1e9;
                if(coins[i] <= j) take = 1 + dp[i][j-coins[i]];
                int not_take=dp[i+1][j];
                dp[i][j]=min(take,not_take);
            }
        }
        if(dp[0][sum]==1e9) return -1;
        return dp[0][sum];
    }
};