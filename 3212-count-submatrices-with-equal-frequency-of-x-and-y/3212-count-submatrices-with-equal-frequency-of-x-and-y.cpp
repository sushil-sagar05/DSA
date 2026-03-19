class Solution {
public:
    vector<vector<int>> psum;
    vector<vector<int>> xCount;
    void PrefixSum(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        psum.assign(n, vector<int>(m, 0));
        xCount.assign(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // x->1 y->-1 .->0
                if(grid[i][j] == 'X'){
                    psum[i][j] = 1;
                    xCount[i][j] = 1;
                } 
                else if(grid[i][j] == 'Y'){
                    psum[i][j] = -1;
                } 
                else{
                    psum[i][j] = 0;
                }
            }
        }
        // prefix sum
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i > 0){
                    psum[i][j] += psum[i-1][j];
                    xCount[i][j] += xCount[i-1][j];
                }
                if(j > 0){
                    psum[i][j] += psum[i][j-1];
                    xCount[i][j] += xCount[i][j-1];
                }
                if(i > 0 && j > 0){
                    psum[i][j] -= psum[i-1][j-1];
                    xCount[i][j] -= xCount[i-1][j-1];
                }
            }
        }
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        PrefixSum(grid);
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(psum[i][j]==0 && xCount[i][j]>0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};