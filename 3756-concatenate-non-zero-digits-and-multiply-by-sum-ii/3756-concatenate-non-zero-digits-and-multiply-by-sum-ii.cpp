class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD=1e9+7;
        vector<int>ans;
        int n=s.size();
        
        vector<long long>pow(n+1,1);
        for(int i=1;i<=n;i++){
            pow[i]=(pow[i-1]*10)%MOD;
        }
        vector<long long>pre(n+1,0);
        vector<int>sum(n+1,0);
        vector<int>cnt(n+1,0);

        for(int i=0;i<n;i++){
            pre[i+1]=pre[i];
            cnt[i+1]=cnt[i];
            sum[i+1]=sum[i]+(s[i]-'0');

            if(s[i]!='0'){
                pre[i+1]=(pre[i]*10 + (s[i]-'0'))% MOD;
                cnt[i+1]++;
            }
        }
        for(auto q:queries){
            int l=q[0],r=q[1];
            long long fsum=sum[r+1]-sum[l];
            int ln=cnt[r+1]-cnt[l];

            long long num=(pre[r+1] - pre[l]*pow[ln]) % MOD;
            if (num < 0) num += MOD;
            ans.push_back((fsum*num)% MOD);
        }
        return ans;
    }
};