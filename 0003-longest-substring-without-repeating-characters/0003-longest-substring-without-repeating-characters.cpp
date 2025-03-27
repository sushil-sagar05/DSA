class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.length();
        int i=0;
        int j=0;
        int output=0;
        set<char> st;
       while(j<size){
        if(st.find(s[j])!=st.end()){
           st.erase(s[i]);
           i=j;

        }else{
            st.insert(s[j]);
            j++;
           output=max(output,j-i);
        }
       }
        return output;
    }
};