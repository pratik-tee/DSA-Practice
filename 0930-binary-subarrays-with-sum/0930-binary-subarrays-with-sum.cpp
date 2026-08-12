class Solution {
public:
    int calculate(vector<int>& nums, int goal){
          if(goal<0) return 0;
        int l=0,r=0,count=0,n=nums.size(),sum=0;
        while(r<n){
           sum+=nums[r];
           while(sum>goal){
             sum-=nums[l];
             l++;
           }
           count=count+(r-l+1);
           r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
     
        return calculate(nums,goal)-calculate(nums,goal-1);
    }
};