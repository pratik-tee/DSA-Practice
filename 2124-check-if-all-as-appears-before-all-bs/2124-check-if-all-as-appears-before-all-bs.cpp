class Solution {
public:
    bool checkString(string s) {
        bool found=false;
        for(char ch:s){
            if(ch=='a' && found==true) return false;
            if(ch=='b') found=true;
        }
        return true;
    }
};