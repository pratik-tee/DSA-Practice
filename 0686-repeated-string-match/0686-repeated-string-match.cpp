class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string p=a;
        int n=b.size();
        int i=1;
        while(p.size()<b.size()){
              p+=a;
              i++;
        }
        if(p.find(b)!=string::npos) return i;
        p+=a;
        if(p.find(b)!=string::npos) return i+1;
        return -1;
    }
};