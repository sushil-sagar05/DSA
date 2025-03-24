class Solution {
public:
    void reverse(vector<int> &nums,int i,int j){
        //Reverse the array
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=n-1;
            k=k%n;
            reverse(nums,i,j);//Reverse original array
            reverse(nums,0,k-1);//Reverse array keth elements
            reverse(nums,k,n-1);//Reverse rest elements
    }
};