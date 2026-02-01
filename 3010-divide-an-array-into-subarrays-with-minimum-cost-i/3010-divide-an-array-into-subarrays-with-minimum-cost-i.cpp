class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        if(n==3){
            int sum=0;
            for(auto it:nums) sum+=it;
            return sum;
        }
        sort(temp.begin()+1,temp.end());
        return temp[0]+temp[1]+temp[2];
    }
};