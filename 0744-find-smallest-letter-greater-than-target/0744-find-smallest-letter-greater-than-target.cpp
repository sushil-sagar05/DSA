class Solution {
public:

    char nextGreatestLetter(vector<char>& letters, char target) {
        set<int> st;
        for(auto it:letters){
            st.insert(it);
        }
        for(auto it:st){
           if(char(it)!=target && char(it)>target){
                return char(it);
           }
        }
        return letters[0];
    }
};