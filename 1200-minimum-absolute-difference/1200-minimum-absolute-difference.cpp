class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        int min_absolute_diff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            int local_diff=arr[i+1]-arr[i];
            min_absolute_diff=min(min_absolute_diff,local_diff);
        }
        vector<vector<int>>result;
        for(int i=0;i<n-1;i++){
            int local_diff=arr[i+1]-arr[i];
            if(min_absolute_diff==local_diff){
                result.push_back({arr[i],arr[i+1]});
            }
        }
        return result;
    }
};