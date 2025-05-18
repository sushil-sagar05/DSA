class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int &stone:stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size() > 1){
            int x=maxHeap.top();
            maxHeap.pop();
            int y=maxHeap.top();
            maxHeap.pop();
            if(x==y){
                x=0;
                y=0;
            }else{
                maxHeap.push(x-y);
            }
        }
        if(maxHeap.size()==0){
            return 0;
        }else return maxHeap.top();
        
    }
};