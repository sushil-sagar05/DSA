class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
        if(nums[i]==0){
                result[i]=nums[i];
        }else if(nums[i]>0){
            // right
                int steps=nums[i];
                int new_idx=(i+steps)%n;
                result[i]=nums[new_idx];
        }else if(nums[i]<0){
            //left
                int steps=abs(nums[i]);
                int new_idx=((i-steps)%n+n)%n;
                result[i]=nums[new_idx];
            }
        }
        return result;
    }
};