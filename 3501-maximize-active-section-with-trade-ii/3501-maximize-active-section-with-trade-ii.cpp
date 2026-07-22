class Solution {
public:
    struct SparseTable {
        vector<vector<int>> st;
        vector<int> lg;
        SparseTable(vector<int>& nums) {
            int n = nums.size();
            lg.resize(n + 1);
            for (int i = 2; i <= n; i++) {
                lg[i] = lg[i / 2] + 1;
            }

            int k = lg[n] + 1;

            st.assign(k, vector<int>(n));
            st[0] = nums;

            for (int j = 1; j < k; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]
                    );
                }
            }
        }

        int query(int l, int r) {
            if (l > r)
                return 0;

            int len = r - l + 1;
            int j = lg[len];

            return max(
                st[j][l],
                st[j][r - (1 << j) + 1]
            );
        }
    };

    vector<int> maxActiveSectionsAfterTrade( string s, vector<vector<int>>& queries) {
        int n = s.size();

        int totalOnes = 0;

        for (char c : s) {
            if (c == '1')
                totalOnes++;
        }

        vector<pair<int, int>> zeroGroups;
        vector<int> zeroGroupIndex(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().second++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
            }

            zeroGroupIndex[i] = zeroGroups.size() - 1;
        }

        int z = zeroGroups.size();

        if (z == 0) {
            return vector<int>(
                queries.size(),
                totalOnes
            );
        }
        vector<int> mergeValue;

        for (int i = 0; i + 1 < z; i++) {
            mergeValue.push_back(
                zeroGroups[i].second +
                zeroGroups[i + 1].second
            );
        }

        SparseTable st(mergeValue);

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int left = -1;

            if (s[l] == '0') {
                int id = zeroGroupIndex[l];

                left = zeroGroups[id].second -
                       (l - zeroGroups[id].first);
            }

            int right = -1;

            if (s[r] == '0') {
                int id = zeroGroupIndex[r];

                right = r -
                        zeroGroups[id].first +
                        1;
            }

            int best = totalOnes;
            int startGroup =
                zeroGroupIndex[l] + 1;

            int endGroup =
                (s[r] == '1'
                    ? zeroGroupIndex[r]
                    : zeroGroupIndex[r] - 1);

            int L = startGroup;
            int R = endGroup - 1;

            if (L <= R) {
                best = max(
                    best,
                    totalOnes + st.query(L, R)
                );
            }

            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {
              best = max( best, totalOnes + left + right );
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <=
                (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1)) {

                int next =
                    zeroGroupIndex[l] + 1;

                best = max( best, totalOnes + left + zeroGroups[next].second);
            }

            if (s[r] == '0' &&zeroGroupIndex[l] <zeroGroupIndex[r] - 1) {

                int prev =  zeroGroupIndex[r] - 1;

                best = max(  best,  totalOnes +  right +  zeroGroups[prev].second);
            }

            ans.push_back(best);
        }

        return ans;
    }
};