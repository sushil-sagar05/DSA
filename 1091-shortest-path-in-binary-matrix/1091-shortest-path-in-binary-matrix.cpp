class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;
        pair<int,int> src={0,0};
        pair<int,int> destination={n-1,n-1};
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[src.first][src.second]=1;
        q.push({1,{src.first,src.second}});
        int drow[]={-1,-1,-1,0,1,1,1,0};
        int dcol[] = {-1,0,1,1,1,0,-1,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r=it.second.first;
            int c=it.second.second;
            if (r == destination.first && c == destination.second)
                return dis;
            for(int i=0;i<8;i++){
                int newR=r+drow[i];
                int newC=c+dcol[i];
                if(newR>=0 && newR<n && newC>=0 && newC<m&&grid[newR][newC]==0&&
                dis + 1 < dist[newR][newC]){
                    dist[newR][newC]=1+dis;
                    q.push({1+dis,{newR,newC}});
                }
            }
        }
        return -1;
    }
};