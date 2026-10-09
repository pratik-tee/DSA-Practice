class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.size();
        int l=0,maxl=0,t=0,f=0;
        for(int r=0;r<n;r++){
            if(s[r]=='T') t++;
            else f++;
            while(min(t,f)>k){
                if(s[l]=='T') t--;
                else f--;
                l++;
            }
            maxl=max(r-l+1,maxl);
        }
        return maxl;
    }
};