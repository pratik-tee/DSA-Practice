class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0],maxi=nums[0];
        int mi=0,mj=0;
        for(int i=1;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                mi=i;
            }
             if(nums[i]>maxi){
                maxi=nums[i];
                mj=i;
            }
        }
        int op1 = max(mi, mj) + 1;
        int op2 = n - min(mi, mj);
        int op3 = mi + 1 + n - mj;
        int op4 = mj + 1 + n - mi;

        return min({op1, op2, op3, op4});

    }
};