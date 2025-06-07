class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int> q;
        q.push(0);
        int color[n];
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        color[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: graph[node]){
                // if the adjacent node is not yet colored
                // you will give opposite color to the node
                if(color[it] == -1){
                    color[it]= !color[node];
                    q.push(it);
                }
                // is the adjacent guy having the same color
                // someone did color on it some other path
                else if (color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
};