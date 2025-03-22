class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // inplace no extraspace
        //first fill the nums1 with nums2
        for(int j=0,i=m;j<n;j++){
            nums1[i]=nums2[j];
            i++;
        }
        //then sort
        sort(nums1.begin(),nums1.end());
    }
};