class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>> sorted_Task;
        for(int i=0;i<n;i++){
            int start_time=tasks[i][0];
            int processing_time=tasks[i][1];
            sorted_Task.push_back({start_time,processing_time,i});
        }
        // sorting
        sort(begin(sorted_Task),end(sorted_Task));
        vector<int> result;
        long long curr_time=0;
        int idx=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        while(idx<n|| !pq.empty()){
            if(pq.empty()&& curr_time<sorted_Task[idx][0]){
                curr_time=sorted_Task[idx][0];
            }
            while(idx<n && sorted_Task[idx][0] <= curr_time){
                pq.push({sorted_Task[idx][1],sorted_Task[idx][2]});
                idx++;
            }
            pair<int,int> currTask= pq.top();
            pq.pop();
            curr_time+=currTask.first;//processing Time;
            result.push_back(currTask.second);
        }
        return result;
    }
};