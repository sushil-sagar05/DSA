class Solution {
public:
    int perfectSum(vector<int>& arr,int n, int target) {
        int size=arr.size();
        int zeroCount = 0;
        for(int x : arr) if(x == 0) zeroCount++;
        vector<vector<int>> t(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++){
            t[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(arr[i-1]<=j  && arr[i-1]!=0){
                    t[i][j]= t[i-1][j-arr[i-1]]+t[i-1][j] ;
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][target]* (1 << zeroCount);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2) return 0;
       int reqSum = (sum + target) / 2;
        return perfectSum(nums,n,reqSum);
    }
};