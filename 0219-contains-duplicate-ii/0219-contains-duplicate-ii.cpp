class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size=nums.size();
        int left=0;
        int right=0;
        while(right<size){
            if(right-left+1<k){
                right++;
            }else if(right-left+1==k){
                if(nums[left]==nums[right+1]){
                    return true;
                }
                left++;
                right++;
            }
        }
        return false;
    }
};