class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size(),minL=INT_MAX;
        string ans="";
        for(int i=0;i<n;i++){
            int count=0;
           for(int j=i;j<n;j++){
                 if(s[j]=='1') count++;
                 if(count==k){
                    string temp=s.substr(i,j-i+1);
                    if(temp.size()<minL || (temp.size()==minL && temp<ans)){
                        minL=temp.size();
                        ans=temp;
                    }
                    break;
                 }
           }
        }
        return ans;
    }
};