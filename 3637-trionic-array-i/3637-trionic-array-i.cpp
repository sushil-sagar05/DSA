class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool p=false,q=false,lst=false;
        int i=1;
        int n=nums.size();
        while(i<n&&nums[i]>nums[i-1] ){
            p=true;
            i++;
        }
        while(i<n&&nums[i]<nums[i-1] ){
            q=true;
            i++;
        }
        while (i<n&&nums[i]>nums[i-1]) {
        lst = true;
        i++;
        }
        if(p&&q&&lst&&i==n) return true;
        else return false;
    }
};