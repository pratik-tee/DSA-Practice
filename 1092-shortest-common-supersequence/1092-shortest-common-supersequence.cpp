class Solution {
public:
    // int helper(int i,int j,string str1,string str2,string s){
    //     if(i==str1.size()-1 || j==str2.size()-1) return 0;
    //     if(str1[i]==str2[j]) return 2+helper(i+1,j+1,str1,str2,s+str1[i]);
    //     return max(1+helper(i+1,j,str1,str2,s+str1[i]),1+helper(i,j+1,str1,str2,s+str2[j]));
    // }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n,j=m;
        string k="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                k+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                    k+=str1[i-1];
                    i--;
                }
            else{
                    k+=str2[j-1];
                    j--;
                }
        }
        while(i>0) {k+=str1[i-1]; i--; }
        while(j>0){ k+=str2[j-1]; j--; }
        reverse(k.begin(),k.end());
        
        return k;
    }
};