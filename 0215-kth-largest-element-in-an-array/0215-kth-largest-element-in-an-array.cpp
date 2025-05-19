class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> Heap;
        for(int &num:nums){
            Heap.push(num);
            if(Heap.size()>k){
                Heap.pop();
            }
        }
        return Heap.top();
    }
};