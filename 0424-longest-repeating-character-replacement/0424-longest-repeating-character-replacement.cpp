class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<int,int>mp;
        int l=0,maxi=0,maxl=0;
        for(int r=0;r<n;r++){
             mp[s[r]]++;
             maxi=max(maxi,mp[s[r]]);
             if(r-l+1-maxi>k){
                  mp[s[l]]--;
                  l++;
             }
             if(r-l+1-maxi<=k) maxl=max(maxl,r-l+1);
        }
        return maxl;
    }
};