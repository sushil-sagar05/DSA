class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(n<m){
            return false;
        }
         sort(begin(s1),end(s1));
            //T.C = O(n-m)*nlogn
            //S.C= O(n)
        for(int i=0;i<=n-m;i++){
            string substring = s2.substr(i,m);
            sort(begin(substring),end(substring));
            if(s1==substring){
                return true;
            }
        }
         
        return false;
    }
};