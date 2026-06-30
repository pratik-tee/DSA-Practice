class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,n=s.size();
        vector<int>hash(3,0);
        int i=0,j=0;
        while(j<n){
            hash[s[j]-'a']++;
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                 ans+=n-j;
                 hash[s[i]-'a']--;
                 i++;
            }
            j++;
        }
        return ans;
    }
};