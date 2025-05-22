class Solution {
public:
    vector<vector<int>> result;
   void solve(int index ,vector<int>& arr, int target,vector<int> temp){
         if (index == arr.size()) {
            if (target == 0) {
                result.push_back(temp);
            }
            return;
        }
        //pick
       if(arr[index] <= target){
        temp.push_back(arr[index]);
        solve(index,arr,target-arr[index],temp);
        temp.pop_back();
       }
        solve(index+1,arr,target,temp);//not pick


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0,candidates,target,temp);
        return result;
    }
};