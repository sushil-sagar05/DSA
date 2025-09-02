class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size=coins.size();
        // use of unsigned long long to avoid overflow
        vector<vector<unsigned long long>> t(size + 1, vector<unsigned long long>
        (amount + 1,0));
        for(int i=0; i<=size; i++) {
            t[i][0] = 1;
        }
        // coin change
        for(int i=1;i<=size;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    t[i][j]=t[i][j-coins[i-1]]+t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return (int)t[size][amount];
    }
};