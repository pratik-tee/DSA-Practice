class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        int n=s.size();
        string k="";
        for(char ch:s){
            if(ch=='(') { st.push(k); k=""; }
            else if(ch==')') {
                reverse(k.begin(),k.end());
                k=st.top()+k;
                st.pop();
            }
            else k+=ch;
        }
        return k;
    }
};