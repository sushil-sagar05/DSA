class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &vis,
    vector<vector<int>> &grid,int drow[],int dcol[]){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            !vis[nrow][ncol] && grid[nrow][ncol]==1){
                bfs(nrow,ncol,vis,grid,drow,dcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                bfs(0,j,vis,grid,drow,dcol);
            }

            if(!vis[n-1][j] && grid[n-1][j]==1){
                bfs(n-1,j,vis,grid,drow,dcol);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                bfs(i,0,vis,grid,drow,dcol);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                bfs(i,m-1,vis,grid,drow,dcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};