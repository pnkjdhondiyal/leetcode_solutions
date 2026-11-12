class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if( need1 ==0 && need2 ==0) return 0;
        long long op1=1LL * cost1 * need1 +1LL * cost2 * need2;
        long long maxneed=max(need1,need2);
        long long op2=costBoth*maxneed;
        long long minneed=min(need1,need2);
        long long op3=0;
        if(minneed==need1)
        {
            op3=costBoth*minneed + (need2 - minneed)*cost2;
        }
        else{
            op3=costBoth*minneed + (need1 - minneed)*cost1;
        }
        return min({op1,op2,op3});
    }
};