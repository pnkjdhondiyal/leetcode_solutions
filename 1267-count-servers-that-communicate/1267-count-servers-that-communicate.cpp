class Solution {
public:
    int drow[4]={-1,1,0,0};
    int dcol[4]={0,0,-1,1};
    int count=0;
    void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&vis ,vector<int>&rowcount,vector<int>&colcount)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(vis[i][j]) return;
        vis[i][j]=1;
        if(grid[i][j]==1){
            if(rowcount[i] > 1 || colcount[j] > 1) count++;
        }
        int m=grid.size();
        int n=grid[0].size();
        for(int x=0;x<4;x++)
        {
            int nr = i + drow[x];
            int nc = j + dcol[x];
            if(nr>=0 && nr<m && nc>=0 && nc<n){
                if(!vis[nr][nc])
                {

                    dfs(grid,nr,nc,vis,rowcount,colcount);
                }
            }
            
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<int>rowcount(grid.size(),0);
        vector<int>colcount(grid[0].size(),0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    rowcount[i]++;
                    colcount[j]++;
                }
            }
        }
        dfs(grid,0,0,vis,rowcount,colcount);
        return count;
    }
};