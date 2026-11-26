class Solution {
public:
    bool solve(vector<int>&nums,int i,vector<int>&vis)
    {
        if(i<0) return false;
        if(i >= nums.size()) return false;
        if(vis[i] ==1) return false;
        vis[i]=1;
        if(nums[i] == 0) return true;
        int r=i+nums[i];
        int l=i-nums[i];
        // bool ans=false;
        bool right=solve(nums,r,vis);
        bool left=solve(nums,l,vis);
        
        return right||left;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),-1);
        return solve(arr,start,vis);
    }
};