class Solution {
public:
    bool horizontal(vector<vector<int>> &grid, long long totalSum){
        int n = grid.size();
        int m = grid[0].size();
        long long prefixSum = 0;
        for(int i = 0; i < n - 1; i++){  
            for(int j = 0; j < m; j++){
                prefixSum += grid[i][j];
            }
            if(prefixSum == totalSum - prefixSum){
                return true;
            }
        }
        return false;
    }

    bool vertical(vector<vector<int>> &grid, long long totalSum){
        int n = grid.size();
        int m = grid[0].size();
        long long prefixSum = 0;
        for(int j = 0; j < m - 1; j++){ 
            for(int i = 0; i < n; i++){
                prefixSum += grid[i][j];
            }
            if(prefixSum == totalSum - prefixSum){
                return true;
            }
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum = 0;
        for(auto &row : grid){
            totalSum += accumulate(row.begin(), row.end(), 0LL);
        }

        return horizontal(grid, totalSum) || vertical(grid, totalSum);
    }
};