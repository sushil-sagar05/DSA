class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge;
        int i,j;
        i=j=0;
        while(i<word1.size()&&j<word2.size()){  
        merge.push_back(word1[i]);
        merge.push_back(word2[j]);
        i++,j++;
        }
        for(;i<word1.size();i++){
             merge.push_back(word1[i]);
        }
         for(;j<word2.size();j++){
          merge.push_back(word2[j]); 
        }
        return merge;
    }
};