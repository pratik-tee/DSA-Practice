class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>mp;
        int maxl=1;
        for(int x:nums) mp[x]++;
        if(mp.count(1))  maxl = max(maxl, mp[1] % 2 ? mp[1] : mp[1]-1);
        mp.erase(1);
        for(auto it:mp){
            long long y=it.first;
            long long x=y;
            int l=0;
                while (true) {
                auto it = mp.find(x);
                if (it == mp.end())  break;
                if (it->second >= 2) {
                    l += 2;
                    if (x > LLONG_MAX / x)
                        break;

                    x *= x;
                } else {
                    l++;
                    break;
                }
            }
            if (l % 2 == 0) l--;
            maxl=max(l,maxl);
        }
        return maxl;
    }
};