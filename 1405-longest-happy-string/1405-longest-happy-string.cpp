class Solution {
public:
    bool causeThree(string &result, char nextChar) {
        if (result.size() < 2) {
            return false;
        }
        if (result[result.size() - 1] == nextChar && result[result.size() - 2] == nextChar) {
            return true;
        } else {
            return false;
        }
    }

    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> Heap;
        if (a > 0) {
            Heap.push({a, 'a'});
        }
        if (b > 0) {
            Heap.push({b, 'b'});
        }
        if (c > 0) {
            Heap.push({c, 'c'});
        }
        string result;

        while (Heap.size() >= 2) {
            pair<int, char> first = Heap.top();
            if (causeThree(result, first.second)) {
                Heap.pop();
                if (Heap.empty()) break;

                pair<int, char> second = Heap.top();
                Heap.pop();

                result += second.second;
                if (--second.first > 0) Heap.push(second);
                Heap.push(first);
            } else {
                Heap.pop();
                result += first.second;
                if (--first.first > 0) Heap.push(first);
            }
        }
        while (!Heap.empty()) {
            pair<int, char> curr = Heap.top();
            Heap.pop();

            if (!causeThree(result, curr.second)) {
                result += curr.second;
                curr.first--;
                if (curr.first > 0 && !causeThree(result, curr.second)) {
                    result += curr.second;
                    curr.first--;
                }
            } else {
                break;
            }
        }

        return result;
    }
};
