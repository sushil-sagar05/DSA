class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> result(n+1,1e9);
        result[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int adjNode=it.first;
                int dist=it.second;
                if(dis+dist<result[adjNode]){
                    result[adjNode]=dis+dist;
                    pq.push({dis+dist,adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,result[i]);
        }
        return ans==1e9?-1:ans;
    }
};