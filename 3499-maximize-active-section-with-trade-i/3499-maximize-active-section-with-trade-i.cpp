class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
           int n = s.size();
        int totalOnes = count(s.begin(), s.end(), '1');
        int ans = totalOnes;
        int i = 0;
        int previousZero = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }

            int length = j - i;
            if (s[i] == '0') {
                if (previousZero > 0) {
                    ans = max(ans, totalOnes + previousZero + length);
                }

                previousZero = length;
            }

            i = j;
        }

        return ans;
    }
};