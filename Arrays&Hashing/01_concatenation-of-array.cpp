class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            int n = nums.size();
            int i=0,j=0;
            vector<int> ans(2*n);
            while(i<n){
                ans[j]=nums[i];
                i++;
                j++;
            }
            i=0;
             while(i<n){
                ans[j]=nums[i];
                i++;
                j++;
            }
        return ans;
        }
    };