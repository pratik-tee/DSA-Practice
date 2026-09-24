class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int e=nums[i],sum=0;
            while(e>0){
                sum+=e%10;
                e/=10;
            }
            if(sum==i) return i;
        }
        return -1;
    }
};