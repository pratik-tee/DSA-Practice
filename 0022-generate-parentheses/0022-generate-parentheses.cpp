class Solution {
public:
    void pratik(vector<string>&ans,string k,int n,int ob,int cb){
        if(ob==cb && ob==n){
            ans.push_back(k);
            return;
        }
        if(ob>n) return;
        pratik(ans,k+'(',n,ob+1,cb);
        if(ob>cb) pratik(ans,k+')',n,ob,cb+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string k="";
        pratik(ans,k,n,0,0);
        return ans;
    }
};