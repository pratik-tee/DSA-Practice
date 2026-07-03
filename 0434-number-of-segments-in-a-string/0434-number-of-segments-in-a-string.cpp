class Solution {
public:
    int countSegments(string s) {
        int n=s.size();
        int i=0,count=0;;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i<n) count++;
            while(i<n && s[i]!=' '){
                i++;
            }
        }
        return count;
    }
};