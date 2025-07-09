leetcode 1394
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;       
        }
        int res=-1;
        for(auto it =freq.begin();it!=freq.end();++it)
        {
            if(it->first==it->second)
            {
                res=max(res,it->first);
            }
        }
        return res;
    }
};