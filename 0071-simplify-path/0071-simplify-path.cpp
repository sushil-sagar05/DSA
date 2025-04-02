class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        string result;

        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                continue;
            }
            string temp;
            while (i < n && path[i] != '/') { 
             temp += path[i];
            i++;
            }
            
            if (temp == "." ) {
                continue;
            }
            if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(temp);
            }
        }
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
