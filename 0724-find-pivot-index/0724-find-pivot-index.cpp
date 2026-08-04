class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int rsum=accumulate(nums.begin(),nums.end(),0);
        int lsum=0;
        for(int i=0;i<n;i++){
            if(i>0) lsum+=nums[i-1];
             rsum-=nums[i];
             if(lsum==rsum) return i;
        }
        return -1;
    }
};