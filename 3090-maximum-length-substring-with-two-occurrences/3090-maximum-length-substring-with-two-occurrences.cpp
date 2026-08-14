class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int l=0,maxl=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[l]]--;
                l++;
            }
            maxl=max(maxl,i-l+1);
        }
        return maxl;
    }
};