class Solution {
public:
    int calculate(vector<int>& nums,int k){
        int l=0,r=0,n=nums.size(),count=0,dist=0;
        vector<int> mp(n+1, 0);
           while(r<n){
                mp[nums[r]]++;
                if (mp[nums[r]]== 1) dist++;
                while(dist>k){
                    mp[nums[l]]--;
                   if (mp[nums[l]] == 0) dist--;
                l++;
                }
                count=count+(r-l+1);
                r++;
            }
        return count;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calculate(nums,k)-calculate(nums,k-1);
    }
};