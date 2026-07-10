class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ps(n);
        for (int i = 0; i < n; i++){
            ps[arr[i].second] = i;
        }
        int log=1;
        while ((1 << log) < n) {
            log++;
        }

        vector<vector<int>>up(n,vector<int>(log));
        int r = 0;
        for (int l = 0; l < n; l++) {
            if (r < l){
                r = l; 
            }                      
            while ((r + 1 < n) && arr[r + 1].first - arr[l].first <= maxDiff) {
                r++;
            }
            up[l][0] = r;
        }
        for (int j = 1; j < log; j++) 
        {
            for (int i = 0; i < n; i++) 
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
        vector<int>ans;
        for(auto it: queries) {
            int sc = ps[it[0]];
            int dt = ps[it[1]];

            if(sc > dt) {
                swap(sc,dt);
            }
            if(sc==dt) 
            {
                ans.push_back(0);
                continue;
            }

            int cr = sc;
            int hp = 0;
            for (int j = log - 1; j >= 0; j--) {
                if (up[cr][j] < dt) {
                    cr = up[cr][j];
                    hp += (1<<j);
                }
            }
            if (up[cr][0] >= dt) {
                ans.push_back(hp + 1);
            } 
            else {
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};