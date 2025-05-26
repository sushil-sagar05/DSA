class Solution {
public:
    unordered_map<char,string> mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
    {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> result;
    void solve(int index,string digits,string &temp){
        if(temp.size()>0 && index==digits.size()){
            result.push_back(temp);
            return;
        }
       if(mp.find(digits[index])!=mp.end()){
            string s  = mp[digits[index]];
            for(char &c:s){
                temp.push_back(c);
                solve(index+1,digits,temp);
                temp.pop_back();
            }
       }
    }
    vector<string> letterCombinations(string digits) {
        string temp;
        solve(0,digits,temp);
        return result;
    }
};