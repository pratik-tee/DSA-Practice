class Solution {
public:
    bool check(int i,int j,set<pair<int,int>>&s){
        for(int k=j;k<j+4;k++){
            if(s.count({i,k})) return false;
            //else s.insert({i,k});
        }
        return true;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<pair<int,int>>s;
        for(auto it:reservedSeats){
              s.insert({it[0],it[1]});
        }
        int count=2*n;

         set<int> rows;

        for (auto &v : reservedSeats) {
            rows.insert(v[0]);
        }
        for(int row:rows){
           bool left = check(row, 2, s);   
            bool mid  = check(row, 4, s);   
            bool right = check(row, 6, s);  

            if(left && right){}
            else if(left || mid || right) count -= 1;
            else count-=2;
        }
        return count;
    }
};