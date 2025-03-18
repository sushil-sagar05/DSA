class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> set(nums.begin(),nums.end());
        int longest=1;
        for(int num : set){
            if(set.find(num-1)==set.end()){
            int x=num;
            int count = 1;
            while(set.find(x+1)!=set.end()){
                x=x+1;
                count++;
            }
            longest = max(longest,count);
        }
        }
        return longest;
    }
};