class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // long long cost=0;
        // while(need1>0 || need2>0){
        //     if(cost1+cost2>costBoth && need1>0 && need2>0){
        //         cost+=costBoth;
        //         need1--;
        //         need2--;
        //     }
        //     else if(need1>0 && cost1>costBoth){
        //         need1--;
        //         cost+=costBoth;
        //     }
        //     else if(need2>0 && cost2>costBoth){
        //         need2--;
        //         cost+=costBoth;
        //     }
        //     else{
        //         if(need1>0){
        //             cost+=cost1;
        //             need1--;
        //         }
        //         if(need2>0){
        //             cost+=cost2;
        //             need2--;
        //         }
        //     }
        // }
        // return cost;
        long long cost=0;
        int both=min(need1,need2);
        cost+=1LL*both*min(costBoth,cost1+cost2);

        need1-=both;
        need2-=both;
        cost+=1LL*need1*min(cost1,costBoth);
        cost+=1LL*need2*min(cost2,costBoth);
        return cost;
    }
};