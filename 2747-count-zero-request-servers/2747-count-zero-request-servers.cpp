class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int m=logs.size();
        int  q=queries.size();
        vector<pair<int,int>>qs(q);
        for(int i=0;i<q;i++) qs[i]={queries[i],i};
        sort(qs.begin(),qs.end());
        int r=0;
       // int m=logs.size();
        int l=0;
        int active=0;
        vector<int>count(n+1,0);
        vector<int>ans(q);
        for(auto &[t,idx]:qs)
        {
            while(r<m && logs[r][1]<=t)
            {
                if(count[logs[r][0]]++ == 0) active++;
                r++;
            }
            while(l<r && logs[l][1] < t-x)
            {
                if(--count[logs[l][0]] == 0) active--;
                l++;
            }
            ans[idx]=n-active;
        }
        return ans;
    }
};