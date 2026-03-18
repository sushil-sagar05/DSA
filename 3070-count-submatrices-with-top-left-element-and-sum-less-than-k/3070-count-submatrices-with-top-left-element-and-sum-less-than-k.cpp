class Solution {
public:
    vector<vector<int>> psum;
    void PrefixSum(vector<vector<int>> &grid){
        psum=grid;
        int n=grid.size();
        int m=grid[0].size();
        for(int j = 1; j < m; j++) {
            psum[0][j] += psum[0][j - 1];
        }
        for(int i = 1; i < n; i++) {
            psum[i][0] += psum[i - 1][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                psum[i][j]=psum[i-1][j] + psum[i][j-1] 
                - psum[i-1][j-1] + psum[i][j];
            }
        }
    
    }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        PrefixSum(grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(psum[i][j]<=k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};