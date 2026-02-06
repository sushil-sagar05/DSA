class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int min_EL=nums[0];
        int max_EL=nums[0];
        int i=0,j=0;
        int max_LEN=1;
        while(j<n){
            min_EL=nums[i];
            max_EL=nums[j];
            while(i<j&&max_EL>k*min_EL){
                i++;
                min_EL=nums[i];
            }
                max_LEN=max(max_LEN,j-i+1);
                j++;
        }
        return n-max_LEN;
    }
};