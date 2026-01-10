class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++)
            t[i][0] = t[i-1][0] + s1[i-1];

        for(int j = 1; j <= n; j++)
            t[0][j] = t[0][j-1] + s2[j-1];
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = t[i-1][j-1];
                } else {
                    t[i][j]=min(
                        t[i-1][j]+s1[i-1],
                        t[i][j-1]+s2[j-1]
                    );
                }
            }
        }

        return t[m][n];
    }
};
