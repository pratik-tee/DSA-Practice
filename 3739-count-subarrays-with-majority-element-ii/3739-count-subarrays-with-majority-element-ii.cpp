class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        mp[0]=1;
        int cums=0;
        long long val=0,ans=0;
        for(int x:nums){
            if(x==target){
                val+=mp[cums];
                cums+=1;
            }
            else{
                cums-=1;
                val-=mp[cums];
            }
            mp[cums]++;
            ans+=val;
        }
        return ans;
    }
};