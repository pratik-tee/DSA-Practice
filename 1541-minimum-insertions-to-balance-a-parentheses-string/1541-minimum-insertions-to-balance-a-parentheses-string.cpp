class Solution {
public:
    int minInsertions(string s) {
        int cnt=0;
        stack<char>st;
        int n=s.size();
        //stack<char>st2;
        for(int i=0;i<n;i++){
           if(s[i]=='(') st.push(s[i]);
           else{
              if(i<n-1 && s[i+1]==')'){
                if(st.empty()) cnt++;
                else st.pop();
                 i++; 
              }
              else{
                 if(st.empty()) cnt=cnt+2;
                 else {  cnt++; st.pop(); }
              }
           }
        }
        return cnt+(st.size()*2);
    }
};