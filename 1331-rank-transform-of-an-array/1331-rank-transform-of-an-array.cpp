class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        multimap<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
           mp.insert({arr[i],i});
        }
        vector<int>ans(n);
       int i=1,pre=INT_MAX;
        for(auto it:mp){
            if(it.first==pre) ans[it.second]=i-1;
            else {ans[it.second]=i;
            i++;
            }
            pre=it.first;
        }
        return ans;
    }
};