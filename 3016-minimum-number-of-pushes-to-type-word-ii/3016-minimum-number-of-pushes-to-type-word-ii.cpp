class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(char ch:word){
            mp[ch]++;
        }
         vector<pair<char, int>> list(mp.begin(), mp.end());
        sort(list.begin(), list.end(), [](const pair<char, int> &o1, const pair<char, int> &o2) {
        return o1.second > o2.second;
         });
        int opr=0;
          for (int i = 0; i < list.size(); i++) {
            int cost = i / 8 + 1;
            opr += cost * list[i].second;
        }
       return opr;
    }
};