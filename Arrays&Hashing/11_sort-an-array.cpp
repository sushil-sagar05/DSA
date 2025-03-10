class Solution {
    public:
        int ps(vector<int>& nums,int low,int high){
            int pivot = nums[low];
            int i=low;
            int j=high;
            while(i<j){
                while(nums[i]<=pivot && i<=high-1){
                    i++;
                }
                while(nums[j]>pivot && j>=low+1){
                    j--;
                }
                if(i<j) swap(nums[i],nums[j]);
            }
            swap(nums[low],nums[j]);
            return j;
        }
        void sort(vector<int>& nums,int low,int high){
            if(low<high){
                int partitionIndex = ps(nums,low,high);
                sort(nums,low,partitionIndex-1);
                sort(nums,partitionIndex+1,high);
            }
        }
        vector<int> sortArray(vector<int>& nums) {
            sort(nums,0,nums.size()-1);
            return nums;
        }
    };