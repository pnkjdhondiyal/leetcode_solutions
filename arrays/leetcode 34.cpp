class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int>vec;
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                // ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        int count=mp[target];
        if(ans==n)
        {
            return {-1,-1};
        }
        else{
            vec.push_back(ans);
            vec.push_back(ans+count-1);
        }
        return vec;
    }
};