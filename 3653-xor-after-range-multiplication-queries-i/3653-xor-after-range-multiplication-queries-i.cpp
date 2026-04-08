class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        int idx,l,r,k,v;
        int mod=1e9+7;
        for(int i=0;i<q;i++){
            l=queries[i][0];
            r=queries[i][1];
            k=queries[i][2];
            v=queries[i][3];
            idx=l;
            while(idx<=r){
                nums[idx]=(nums[idx]*1LL*v)%mod;
                idx+=k;
              }
                
        }
        int xorr=0;
        for(auto num:nums){
            xorr^=num;
        }
        return xorr;
    }
};