class Solution {
public:
    bool possible(vector<int>&nums,int threshold,int divi){
        int sum=0;
          for(int i=0;i<nums.size();i++){
              sum+=(nums[i]+divi-1)/divi;
          }
          return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(nums,threshold,mid)) h=mid-1;
            else l=mid+1;
        }
        return l;
    }
};