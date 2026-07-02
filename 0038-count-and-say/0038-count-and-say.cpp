class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string k="1";
        
        for(int i=2;i<=n;i++){
            string p="";
            int count=1;
             int j=0;
             while(j<k.size()-1){
                 if(k[j]==k[j+1]) count++;
                 else{
                    p+=to_string(count);
                    p+=k[j];
                    count=1;
                 }
                 j++;
             }
             if(count!=0) p+=to_string(count);
             p+=k[j];
             k=p;
        }
        return k;
    }
};