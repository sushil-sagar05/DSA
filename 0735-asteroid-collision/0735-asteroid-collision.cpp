class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> result;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0) {
                    if (abs(st.top()) < abs(asteroids[i])) {
                        st.pop();
                    } else if (abs(st.top()) == abs(asteroids[i])) {
                        st.pop();
                        goto skipPush;
                    } else {
                        goto skipPush;
                    }
                }
                st.push(asteroids[i]);
            }
            skipPush:;
        }

        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        while (!temp.empty()) {
            result.push_back(temp.top());
            temp.pop();
        }

        return result;
    }
};











