class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,  int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        vector<long long> freq(100001, 0);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            mx = max(mx, d);
        }

        long long total = 0;
        for (int d = 1; d <= mx; d++) {
            total += d * freq[d];
        }

        if (k >= total) return 0;

        for (int d = mx; d > 0 && k > 0; d--) {
            long long cnt = min(freq[d], k);
            freq[d] -= cnt;
            freq[d - 1] += cnt;
            k -= cnt;
        }

        long long ans = 0;
        for (int d = 1; d <= mx; d++) {
            ans += 1LL*d * d * freq[d];
        }

        return ans;
    }
};