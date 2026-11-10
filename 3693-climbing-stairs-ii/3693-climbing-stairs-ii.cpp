class Solution {
public:
    int climb(int i,int n ,vector<int >&costs,vector<int>&dp)
    {
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        //take 1
        int take1=INT_MAX;
        int take2=INT_MAX;
        int take3=INT_MAX;
        if(i+1 <=n)
        {
            int j=i+1;
            take1= costs[j-1] + (j - i) *(j - i) + climb(j,n,costs,dp);
        }
        if(i+2 <=n)
        {
            int j=i+2;
            take2= costs[j-1] + (j - i) *(j - i) + climb(j,n,costs,dp);
        } 
        if(i+3 <=n)
        {
            int j=i+3;
            take3= costs[j-1] + (j - i) *(j - i)+ climb(j,n,costs,dp);
        } 
        return dp[i]=min(take1, min(take2,take3)) ;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return climb(0,n,costs,dp);
    }
};