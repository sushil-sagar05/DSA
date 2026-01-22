class Solution {
public:
    void do_operation(vector<int> &nums){
    int min_sum=nums[0]+nums[1];
    int idx=0;
    for(int i=0;i<nums.size()-1;i++){
            int curr_sum=nums[i]+nums[i+1];
            if(curr_sum<min_sum){
                min_sum=curr_sum;
                idx=i;
            }
        }
        nums[idx]=min_sum;
        nums.erase(nums.begin()+idx+1);
}
    int minimumPairRemoval(vector<int>& nums) {
    int n=nums.size();
    if(n<=1||is_sorted(nums.begin(),nums.end())) {
        return 0;
    }
    int operations=0;
    while(nums.size()>1&&!(is_sorted(nums.begin(),nums.end()))){
    do_operation(nums);
    operations++;
   }
   return operations;
    }
};