class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int l=0,maxl=0;
        for(int i=0;i<n;i++){
            int c=nums[i];
            mp[c]++;
            int len=i-l;
            while(mp[nums[i]]>k){
                int p=nums[l];
                mp[p]--;
                l++;
            }
            maxl=max(maxl,i-l+1);
        }
        return maxl;
    }
};