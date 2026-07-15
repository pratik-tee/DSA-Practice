class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int e=n*(n+1);
        int o=n*n;
        while(o!=0){
          int temp=o;
          o=e%o;
          e=temp;
        }
        return e;
    }
};