class Solution {
public:
    typedef pair<int,int>P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
      //frequency
        for(int num:nums){
            mp[num]++;
       }
    priority_queue<P,vector<P>,greater<P>> pq;//min heap
    //push element in min heap
    //maintains size
    for(auto it:mp){
        int value = it.first;
        int freq = it.second;
        pq.push({freq,value});
        if(pq.size()>k){
            pq.pop();
        }
    }
    //result
    vector<int>result;
    while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
    }
};

