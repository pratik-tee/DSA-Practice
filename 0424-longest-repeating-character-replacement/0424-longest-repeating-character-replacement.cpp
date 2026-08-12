class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(),maxl=0,l=0,r=0,maxf=0;
         unordered_map<char,int>map;
         while(r<n){
            map[s[r]]++;
            maxf=max(maxf,map[s[r]]);
             if(r-l+1-maxf>k){
               map[s[l]]--;
               l++;
            }
           if(r-l+1-maxf<=k )maxl=max(maxl,r-l+1);
            r++;
         }
         
         return maxl;
    }
};