class Solution {
public:
    string LCS(string text1,string text2,int m,int n){
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        } 
        int i=m,j=n;
        string s="";
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                s.push_back(text1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i][j-1]>dp[i-1][j]){
                    j--;
                }else{
                    i--;
                }
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string shortestCommonSupersequence(string str1, string str2) {
       int m=str1.size();
       int n= str2.size();
       string lcs = LCS(str1, str2, m,n);
        string scs = "";
        int i = 0, j = 0;

        for (char c : lcs) {
            while (i < str1.size() && str1[i] != c){
                scs.push_back(str1[i++]);
            }
            while (j < str2.size() && str2[j] != c){
                scs.push_back(str2[j++]);
            }
            scs.push_back(c);
            i++; j++;
        }
         scs += str1.substr(i);
        scs += str2.substr(j);

        return scs;
    }
};