class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> Heap;
        vector<int> TaskFreq(26,0);
        int time=0;
        for(char &ch : tasks){
            TaskFreq[ch-'A']++;
        }
        for( int i=0;i<26;i++){
            if(TaskFreq[i]>0)
                Heap.push(TaskFreq[i]);
        }
        while(!Heap.empty()){
            vector<int> frequency;
            for(int i=1;i<=n+1;i++){
                if(!Heap.empty()){
                int freq=Heap.top();
                Heap.pop();
                freq--;
                frequency.push_back(freq);
                }
            }
            for(int &f:frequency){
                if(f>0){
                    Heap.push(f);
                }
            }
            if(Heap.empty()){
                time+=frequency.size();
            }else{
                time+=n+1;
            }
        }
        return time;
    }
};
    //O(N)