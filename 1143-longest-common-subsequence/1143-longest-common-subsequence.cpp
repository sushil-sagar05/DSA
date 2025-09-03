class Solution {
public:
    int t[1005][1005];
    int lcs(string text1,string text2,int m,int n){
        if(m==0||n==0) {
        return t[m][n]=0;
    }
        if(t[m][n]!=-1){
            return t[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return t[m][n]=1+lcs(text1,text2,m-1,n-1);
        }else{
            return t[m][n]= max(lcs(text1,text2,m-1,n),lcs(text1,text2,m,n-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        memset(t,-1,sizeof(t));
        return lcs(text1,text2,m,n);
    }
};