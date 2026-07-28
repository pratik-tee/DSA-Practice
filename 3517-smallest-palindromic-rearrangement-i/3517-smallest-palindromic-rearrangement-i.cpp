class Solution {
public:
    string smallestPalindrome(string s) {
       vector<int>fr(26,0);
       for(char c:s){
        fr[c-'a']++;
       }
       string left="";
       string mid="";
       for(int i=0;i<26;i++){
              left+=string(fr[i]/2,'a'+i);
          if(fr[i]%2!=0) mid=char('a'+i);
       }
       string right=left;
       reverse(right.begin(),right.end());
       return left+mid+right;

    }
};