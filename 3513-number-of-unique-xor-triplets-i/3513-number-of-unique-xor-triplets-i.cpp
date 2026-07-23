class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return 1;
        if (n == 2)  return 2;
        int res = 1;
        while (res <= n) {
            res <<= 1;
        }
        return res;
    }
};