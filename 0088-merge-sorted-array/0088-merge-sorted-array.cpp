class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j,k;
        i=j=k=0;
        vector<int> merge(m+n,0);
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
            merge[k]=nums1[i];
            k++;
            i++;
            }else{
                merge[k]=nums2[j];
                k++;
                j++;
            }
        }
        for(;i<m;i++){
            merge[k]=nums1[i];
            k++;
        }
        for(;j<n;j++){
            merge[k]=nums2[j];
            k++;
        }
        for(int l=0;l<merge.size();l++){
            nums1[l]=merge[l];
        }
    }
};