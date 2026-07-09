class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>cost(n,0);
        int cnt=0;
        for(int i=1;i<n;i++){
          if(nums[i]-nums[i-1]>maxDiff) cnt++;
           cost[i]=cnt;
        }
        for(auto q:queries){
            int i=q[0],j=q[1];
            ans.push_back(cost[i]==cost[j]);
        }
        return ans;
    }
};