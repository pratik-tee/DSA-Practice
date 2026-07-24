class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int MAXX = 2048;

        vector<bool> pairXor(MAXX, false);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> tripletXor(MAXX, false);
        for (int x = 0; x < MAXX; x++) {
            if (pairXor[x]) {
                for (int num : nums) {
                    tripletXor[x ^ num] = true;
                }
            }
        }

        int ans = 0;

        for (bool x : tripletXor) {
            if (x) ans++;
        }

        return ans;
    }
};