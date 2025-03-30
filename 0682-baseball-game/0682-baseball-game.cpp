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
            //     int lastsum = 0;
            //   int lastfirst=st.top();
            //   lastsum+=lastfirst;
            //     if(!st.empty()){
            //     st.pop();
            //      lastsum+=st.top();
            //     }
            //     st.push(lastfirst);
            //     st.push(lastsum);
            //  }
            if(st.size()>=2){
            int last = st.top();
            st.pop();
            int secondlast=st.top();
            st.push(last);
            st.push(last+secondlast);
            }
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