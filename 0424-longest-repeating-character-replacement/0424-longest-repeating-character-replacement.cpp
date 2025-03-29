class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlength=0;
        int maxfreq=0;
        unordered_map<int,int> mp;
        while(r<s.length()){
            mp[s[r]-'A']++;
            maxfreq=max(maxfreq,mp[s[r]-'A']);
            if((r-l+1)-maxfreq>k){
                mp[s[l]-'A']--;
            l=l+1;
            }
            if((r-l+1)-maxfreq<=k){
                maxlength=max(maxlength,r-l+1);
                r++;
            }
        }
        return maxlength;
    }
};