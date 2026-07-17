class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx =*max_element(nums.begin(), nums.end());
        vector<long long>fq(mx+1,0);
        for (int x:nums)
            fq[x]++;
        vector<long long>cnt(mx+1,0);
        for (int d =1;d<=mx;d++) {
            for (int m = d; m <= mx; m += d) {
                cnt[d] += fq[m];
            }
        }
        vector<long long> temp(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            temp[d] = cnt[d] * (cnt[d] - 1) / 2;

            for (int m = 2 * d; m <= mx; m += d) {
                temp[d] -= temp[m];
            }
        }
        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + temp[d];
        }
        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};