class Solution {
public:
typedef long long ll;
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        set<pair<ll,ll>> KMinimum;// stores (k-1) min elements
        set<pair<ll,ll>> remaining;
        ll sum=0; // stores sum of (k-1)min elements
        int i=1;
        while(i-dist<1){
            KMinimum.insert({nums[i],i});
            sum+=nums[i];
            if(KMinimum.size()>k-1){
                pair<ll,ll> temp=*KMinimum.rbegin();
                sum-=temp.first;
                remaining.insert(temp);
                KMinimum.erase(temp);
            }
            i++;
        }
        ll result=LONG_MAX;
        while(i<n){
            KMinimum.insert({nums[i],i});
            sum+=nums[i];
            if(KMinimum.size()>k-1){
                pair<ll,ll> temp=*KMinimum.rbegin();
                sum-=temp.first;
                remaining.insert(temp);
                KMinimum.erase(temp);
            }
            result=min(result,sum);
            // shift window
            // i-dis wala element will removed
            pair<ll ,ll> remove={nums[i-dist],i-dist};
            if(KMinimum.count(remove)){
            KMinimum.erase(remove);
            sum-=remove.first;
            if(!remaining.empty())
            {
                pair<ll,ll> temp=*remaining.begin();
                KMinimum.insert(temp);
                sum+=temp.first;
                remaining.erase(temp);
            }
            }else{
                remaining.erase(remove);
            }
            i++;
        }
        return nums[0]+result;
    }
};