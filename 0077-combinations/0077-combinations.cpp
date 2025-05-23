class Solution {
public:
    vector<vector<int>> result;
    void solve(int i,int n,int k ,vector<int> &arr){
        if(k==0){
            result.push_back(arr);
            return ;
        }
        if(i>n){
            return;
        }
           // pick
           arr.push_back(i);
           solve(i+1,n,k-1,arr);
           arr.pop_back();
           // not pick
           solve(i+1,n,k,arr);
       
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,n,k,temp);
        return result;
    }
};