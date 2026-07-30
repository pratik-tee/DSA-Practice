class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int k=n/8;
        int r=n%8,sum=0;
        for(int i=1;i<=k;i++){
            sum+=8*i;
        }
        r=r*(k+1);
        return sum+r;
    }
};