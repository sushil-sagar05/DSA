class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        // always push first word to result
        result.push_back(words[0]);
        for(int i = 1;i<words.size();i++){
            string temp1=words[i];
            sort(temp1.begin(),temp1.end());
            // sort last word of result
            string temp2=result.back();
            sort(temp2.begin(),temp2.end());
            if(temp1==temp2){
                continue;
            }else{
                result.push_back(words[i]);
            }
        }
    return result;
    }
};