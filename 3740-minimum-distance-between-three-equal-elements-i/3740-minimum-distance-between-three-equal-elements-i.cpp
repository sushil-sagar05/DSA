class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return -1;
        int min_dis=INT_MAX;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if(j==i)
                            continue;
                        for(int k=0;k<n;k++)
                            {
                                if(k==i || k==j)
                                    continue;

                                if(nums[i]==nums[j] && nums[j]==nums[k])
                                {
                                    int cur_dis=abs(i-j)+abs(j-k)+abs(k-i);
                                    min_dis=min(min_dis,cur_dis);
                                }
                            }
                    }
            }

        if(min_dis==INT_MAX)
            return -1;
        else
            return min_dis;
        
    }
};