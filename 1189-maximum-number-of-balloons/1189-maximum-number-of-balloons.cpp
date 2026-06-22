class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>hash(26,0);
        for(char ch:text){
            if(ch=='b' || ch=='a' || ch=='l' || ch=='o' || ch=='n'){
                hash[ch-'a']++;
            }
        }
        int mini=min({hash['b'-'a'],hash['a'-'a'],hash['l'-'a']/2,hash['o'-'a']/2,hash['n'-'a']});
        return mini;
    }
};