class Solution {
public:
    int minPairSum(vector<int>& nums) {
    vector<int> output;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int left=0,right=n-1;
    while(left<right){
        output.push_back(nums[left]+nums[right]);
        left++;
        right--;
    }
    int output_result=*max_element(output.begin(),output.end());
    return output_result; 
    }
};