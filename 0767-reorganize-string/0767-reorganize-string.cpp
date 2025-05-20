class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char &ch:s){
            freq[ch-'a']++;
        }
         priority_queue<pair<int, char>> Heap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (freq[i] > (s.length() + 1) / 2) return "";
            Heap.push({freq[i], 'a' + i});
        }
        }
        string result;
        while(Heap.size()>=2){
            pair<int, char> first = Heap.top();
            Heap.pop();
            pair<int, char> second = Heap.top();
            Heap.pop();
            result+=first.second;
            result+=second.second;
            if (--first.first > 0) Heap.push(first);
            if (--second.first > 0) Heap.push(second);
        }
        while(!Heap.empty()){
            if(Heap.top().first>1) return "";
            result+=Heap.top().second;
            Heap.pop();
        }
        return result;
    }
};