class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        pair<int,int> src={0,0};
        pair<int,int> destination={n-1,m-1};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[src.first][src.second]=0;
        pq.push({0,{src.first,src.second}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if (r == destination.first && c == destination.second) return dis;
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n &&ncol<m){
                    int newEffort=max(abs(heights[r][c]-heights[nrow][ncol]),dis);
                    if(newEffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};