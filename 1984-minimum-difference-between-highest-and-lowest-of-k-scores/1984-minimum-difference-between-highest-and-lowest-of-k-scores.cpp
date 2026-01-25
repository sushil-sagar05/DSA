class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int min_result=INT_MAX;
        int i=0,j=k-1;
        while(j<n){
            int maxEL=nums[j];
            int minEL=nums[i];
            min_result=min(min_result,maxEL-minEL);
            i++;
            j++;
        }
        return min_result;
    }
};