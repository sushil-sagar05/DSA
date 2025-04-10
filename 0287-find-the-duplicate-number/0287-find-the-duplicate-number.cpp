class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        for(int i=0;i<n;i++){
            if(mp[i]>1){
                return i;
            }
        }
        return -1;
    }
};