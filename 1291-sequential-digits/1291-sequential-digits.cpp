class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int s=1;s<=9;s++){
            int num=0;
            for(int d=s;d<=9;d++){
               num=num*10+d;
               if(num>=low && num<=high) ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};