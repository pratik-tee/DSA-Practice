class Solution {
public:
    int isPali(string s,int l,int r){
        while(r<s.size() && l>=0 && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n=s.size(),maxlen=0,start=0;
        for(int i=0;i<n;i++){
            int odd=isPali(s,i,i);
            int even=isPali(s,i,i+1);
            int len=max(even,odd);
            if(len>maxlen){
                maxlen=len;
                start=i-(len-1)/2;
            }
        }
       return s.substr(start,maxlen);
    }
};