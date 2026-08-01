class Solution {
public:
    // bool check(int r,int c,vector<string>&temp,int n){
    //     int i=r,j=c;
    //     for(int k=0;k<j;k++){
    //         if(temp[i][k]=='Q') return false;
    //     }
    //     i=r,j=c;
    //     while(i>=0 && j>=0){
    //         if(temp[i][j]=='Q') return false;
    //         i--;
    //         j--;
    //     }
    //     i=r,j=c;
    //     while(i<n && j>=0){
    //          if(temp[i][j]=='Q') return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    void pratik(vector<string>&temp,vector<vector<string>>&ans,int n,int col,vector<int>&rowc,vector<int>&lowerd,vector<int>&upperd){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            if(rowc[row]==0 && lowerd[row+col]==0 && upperd[n-1+col-row]==0) {
                temp[row][col]='Q';
                rowc[row]=1;
                lowerd[row+col]=1;
                upperd[n-1+col-row]=1;
                pratik(temp,ans,n,col+1,rowc,lowerd,upperd);
                rowc[row]=0;
                upperd[n-1+col-row]=0;
                lowerd[row+col]=0;
                temp[row][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        vector<int>rowc(n,0);
        vector<int>lowerd(2*n-1);
        vector<int>upperd(2*n-1);
        pratik(temp,ans,n,0,rowc,upperd,lowerd);
        return ans;
    }
};