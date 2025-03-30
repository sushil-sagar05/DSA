class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int result=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                st.pop();
            }
            if(operations[i]=="D"){
                st.push(2*st.top());
            }
            if(operations[i]=="+"){
                int lastsum = 0;
              int lastfirst=st.top();
              lastsum+=lastfirst;
                if(!st.empty()){
                st.pop();
                 lastsum+=st.top();
                }
                st.push(lastfirst);
                st.push(lastsum);
             }
           if (operations[i] == "C" || operations[i] == "D" || operations[i] == "+") {
            }
            else{
            st.push(stoi(operations[i]));
            }
            }
     while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};