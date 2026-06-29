class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        st.push(0);
        int n=heights.size(),maxa=INT_MIN;
        for(int i=0;i<=n;i++){
            while(!st.empty() && ((i==n || heights[st.top()]>heights[i]) )){
             int h=heights[st.top()];
             st.pop();
             int width;
             if(st.empty()) width=i;
             else width=i-st.top()-1;
             maxa=max(h*width,maxa);
           }
           st.push(i); 
        }
        return maxa;
    }
};