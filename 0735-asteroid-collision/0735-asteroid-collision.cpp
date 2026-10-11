class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto x:asteroids){
            bool col=false;
            while(!st.empty() && st.top()>0 && x<0){
                if(st.top()==abs(x)) { st.pop(); col=true; break; }
                else if(st.top()<abs(x)) st.pop();
                else{
                    col=true;
                    break;
                }
            }
            if(col==false) st.push(x);

        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};