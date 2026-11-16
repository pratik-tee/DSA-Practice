class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        string m="";
        while(n>k){
            m="";
            int j=0;
            while(j<n){
               string p=s.substr(j,k);
               int sum=0;
               for(int i=0;i<p.size();i++){
                  sum+=p[i]-'0';
               }
               m+=to_string(sum);
               j+=k;
            }
            s=m;
            n=s.size();
        }
       return s;
    }
};