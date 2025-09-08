class Solution {
public:
    int lcs(string word1,string word2,int m,int n){
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
    int minDistance(string word1, string word2) {
        int a_length=word1.size();
        int b_length=word2.size();
        int lcs_res=lcs(word1,word2,a_length,b_length);
        return (a_length-lcs_res)+(b_length-lcs_res);
    }
};