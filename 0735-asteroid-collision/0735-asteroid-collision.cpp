class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> result;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                   while(!st.empty() && st.top()>0 && abs(st.top())<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && abs(asteroids[i])==st.top()){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
            }
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











