class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        if(nums.size() ==1) return 1;
        int minc=1;
        int mdsc=1;
        for(int i=0;i<nums.size();i++)
        {
            int inc=1;
            for(int j=i+1;j<nums.size();j++)
            {   
                if(nums[j] > nums[j-1]) inc++;
                else{
                    break;
                }
            }
            minc=max(minc,inc);
        }
        for(int i=0;i<nums.size();i++)
        {
            int dsc=1;
            for(int j=i+1;j<nums.size();j++)
            {   
                if(nums[j] < nums[j-1]) dsc++;
                else{
                    break;
                }
            }
            mdsc=max(mdsc,dsc);
        }
        cout<<mdsc << " -" <<minc;
        return max(mdsc,minc);
    }
};