class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        int minL=INT_MAX,sI=-1;
        unordered_map<char,int>mp;
        for(char c:t){
            mp[c]++;
        }
        int cnt=0,l=0;
        for(int r=0;r<n;r++){
           
             if(mp.count(s[r]) && mp[s[r]]>0){
                cnt++;
             }
              mp[s[r]]--;
             while(cnt==m){
                if(r-l+1<minL){
                    minL=r-l+1;
                    sI=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt=cnt-1;
                l++;
             }
        }

          if(sI == -1) return "";
        return s.substr(sI,minL);
        
    }
};