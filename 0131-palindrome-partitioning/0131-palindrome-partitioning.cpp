class Solution {
public:
    vector<vector<string>> result;
    bool isPallindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
           if (s[i]!=s[j]) return false;
           i++;
           j--;
        }
        return true;
    }
    void solve(int index,string s,vector<string> &temp){
        vector<string> substring;
        if(index == s.size()){
            result.push_back(temp);
        }
        for(int i=index;i<=s.size();i++){
            string str;
            str=s.substr(index, i - index + 1);
            if(isPallindrome(str)){
                temp.push_back(str);
                solve(i+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0,s,temp);
        return result;
    }
};