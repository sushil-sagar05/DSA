class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<int , pair<int,int>>> Heap;
         int n=points.size();
         for(int i=0;i<n;i++){
         Heap.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],{points[i][0],points[i][1]}});
         if(Heap.size()>k){
            Heap.pop();
         }
         }
        vector<vector<int>>result;
        while(!Heap.empty()){
            pair<int, pair<int,int>> point = Heap.top();
            Heap.pop();
            result.push_back({point.second.first,point.second.second});
        }
        return result;
    }
};