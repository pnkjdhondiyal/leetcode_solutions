class Solution {
public:
    int drow[4]={-1,1,0,0};
    int dcol[4]={0,0,-1,1};
    int count=0;
    bool check(vector<vector<int>>&grid,int i,int j)
    {

        int m = grid.size();
    int n = grid[0].size();

    // check row
    for(int col=0; col<n; col++)
    {
        if(col!=j && grid[i][col]==1)
            return true;
    }

    // check column
    for(int row=0; row<m; row++)
    {
        if(row!=i && grid[row][j]==1)
            return true;
    }

    return false;
    }
    void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&vis)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(vis[i][j]) return;
        vis[i][j]=1;
        if(grid[i][j]==1){
            if(check(grid,i,j)) count++;
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

                    dfs(grid,nr,nc,vis);
                }
            }
            
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        dfs(grid,0,0,vis);
        return count;
    }
};