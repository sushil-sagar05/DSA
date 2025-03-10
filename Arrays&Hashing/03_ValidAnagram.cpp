class Solution {
    public:
        bool isAnagram(string s, string t) {
            int i;
            int H[26]={0};
            if(s.length()!=t.length()) return false;
            for( i=0;s[i]!='\0';i++){
                H[s[i]-97]+=1;
            }
            for( i=0;t[i]!='\0';i++){
                H[t[i]-97]-=1;
                if(H[t[i]-97]<0){
                    return false;
                    break;
                }
            }
            for(i=0;i<26;i++){
               if( H[i]!=0){
                return false;
               }
            }
            return true;
        }
    };
    