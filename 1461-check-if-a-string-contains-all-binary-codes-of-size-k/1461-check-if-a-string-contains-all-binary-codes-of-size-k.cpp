class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n=s.length();
        int codes=pow(2,k);
        for(int i=k;i<=n;i++){
            string sb=s.substr(i-k,k);
            if(!st.count(sb)){
                st.insert(sb);
                codes--;
            }
            if(codes==0){
                return true;
            }
        }
        return false;
    }
};