class Solution {
public:
    vector<int> resultArray(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans,ans1;
        ans.push_back(arr[0]);
        ans1.push_back(arr[1]);
        for(int i=2;i<n;i++){
            if(ans.back()>ans1.back()) ans.push_back(arr[i]);
            else ans1.push_back(arr[i]);
        }
        for(int k:ans1){
            ans.push_back(k);
        }
        return ans;
    }
};