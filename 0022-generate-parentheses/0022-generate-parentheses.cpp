class Solution {
public:
     void solve(int open,int close,string output,vector<string>&v){
        if(open==0&&close==0){
            v.push_back(output);
            return;
        }
        if(open!=0){
            string output1=output;
            output1.push_back('(');
            solve(open-1,close,output1,v);

        }
        if(close>open){
            string output2=output;
            output2.push_back(')');
            solve(open,close-1,output2,v);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int close = n;
        int open=n;
        string output="";
        solve(open,close,output,v);
        return v;
    }
};