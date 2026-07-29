class Solution {
public:
    long long LIMIT = 1'000'000;
    long long helper(vector<int>& fre, int remaining) {
        long long wys = 1;
        for (int i = 0; i < 26; i++) {
            int count = fre[i];
            for (int j = 1; j <= count; j++) {
                wys = wys * (remaining - count + j) / j;
                if (wys > LIMIT) {
                    return LIMIT + 1;
                }
            }
            remaining -= count;
        }

        return wys;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> fre(26, 0);
        for (char ch : s) {
            fre[ch - 'a']++;
        }
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (fre[i] % 2 == 1) {
                middle = char('a' + i);
            }

            fre[i] /= 2;
        }

        int halfLength = s.size() / 2;
        if (helper(fre, halfLength) < k) {
            return "";
        }

        string left = "";

        for (int position = 0; position < halfLength; position++) {
            for (int ch = 0; ch < 26; ch++) {
                if (fre[ch] == 0) {
                    continue;
                }
                fre[ch]--;
                int remaining = halfLength - position - 1;
                long long wys = helper(fre, remaining);

                if (wys >= k) {
                    left += char('a' + ch);
                    break;
                }
                k -= wys;
                fre[ch]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};