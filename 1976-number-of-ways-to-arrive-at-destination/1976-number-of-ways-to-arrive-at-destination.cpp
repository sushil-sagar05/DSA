class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<long> dis(n,LONG_MAX/2);
        vector<int> ways(n,0);
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edW = it.second;
                // this is the first time i am arriving
                // with short distance
                if(dist+edW<dis[adjNode]){
                    dis[adjNode]= dist+edW;
                    pq.push({dist+edW,adjNode});
                    ways[adjNode]=ways[node];
                }else if(dist+edW == dis[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};