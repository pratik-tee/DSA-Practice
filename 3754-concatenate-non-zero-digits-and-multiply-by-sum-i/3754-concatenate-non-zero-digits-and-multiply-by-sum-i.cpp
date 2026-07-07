class Solution {
public:
    long long sumAndMultiply(int n) {
        long long k=n,sum=0,num=0;
        while(k!=0){
            int r=k%10;
            k=k/10;
            if(r==0) continue;
            sum+=r;
            num=num*10+r;
        }
        long long p=0;
        while(num!=0){
            int r=num%10;
            num=num/10;
            p=p*10+r;
        }
        return 1LL*p*sum;
    }
};