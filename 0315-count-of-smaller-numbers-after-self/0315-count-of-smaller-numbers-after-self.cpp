class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      int n=nums.size();
        vector<int>count;
        vector<int>sorted;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
           auto it=lower_bound(sorted.begin(),sorted.end(),nums[i]);
           count.push_back(it-sorted.begin());
           sorted.insert(it,nums[i]);
        }
      reverse(count.begin(),count.end());
      return count;
    }
};