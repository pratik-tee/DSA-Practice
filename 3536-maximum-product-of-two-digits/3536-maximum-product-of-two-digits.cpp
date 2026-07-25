class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n!=0){
            int k=n%10;
            n=n/10;
           ans.push_back(k);
        }
        int k=ans.size();
        sort(ans.begin(),ans.end());
        return ans[k-1]*ans[k-2];
    }
};