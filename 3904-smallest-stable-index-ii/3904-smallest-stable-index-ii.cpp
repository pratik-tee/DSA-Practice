class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
          int mi=INT_MAX,ma=0,n=nums.size();
        vector<int>mini=nums;
        for(int i=n-1;i>=0;i--){
             mi=min(mi,mini[i]);
             mini[i]=mi;
        }
        for(int i=0;i<n;i++){
            ma=max(ma,nums[i]);
            if(ma-mini[i]<=k) return i;
        }
        return -1;
    }
};