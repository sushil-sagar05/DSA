class FreqStack {

public:
    unordered_map<int, int> freqMap;
    list<stack<int>> stList;
    FreqStack() {
        
    }

    void push(int x) {
        int freq = ++freqMap[x];
        if (freq > stList.size()) {
            stList.push_back(stack<int>());
        }
        auto it = stList.begin();
        advance(it, freq - 1);
        it->push(x);
    }

    int pop() {
        auto it = stList.rbegin();
        int x = it->top();
        it->pop();
        freqMap[x]--;
        if (it->empty()) {
            stList.pop_back();
        }
        if (freqMap[x] == 0) {
            freqMap.erase(x);
        }
        return x;
    }
};




/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */