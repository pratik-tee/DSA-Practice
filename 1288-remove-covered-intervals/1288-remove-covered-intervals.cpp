class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int c=intervals[0][0],d=intervals[0][1],count=1;
        for(auto k:intervals){
            int a=k[0];
            int b=k[1];
            if(c>a || b>d ){
                c=a;
                d=b;
                count++;
            }
        }
        return count;
    }
};