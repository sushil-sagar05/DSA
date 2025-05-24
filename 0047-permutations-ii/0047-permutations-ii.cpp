class Solution {
public:
    vector<vector<int>> result;
    int size;
    void solve(unordered_map<int,int> &mp,vector<int>& temp){
        if(temp.size()==size){
            result.push_back(temp);
            return ;
        }
        for(auto & [num,count]:mp){
            if(count==0){
                continue;
            }
            
            temp.push_back(num);
            mp[num]--;
            solve(mp,temp);
            //backtrack
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        size=nums.size();
        for(int &num:nums){
            mp[num]++;
        }
        vector<int> temp;
        solve(mp,temp);
        return result;
    }
};