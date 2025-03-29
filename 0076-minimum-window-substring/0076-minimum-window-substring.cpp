class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n){
            return "";
        }
        unordered_map<char,int> mp;
        //store the frequency of t in map;
        for(char &ch:t){
            mp[ch]++;
        }
        int i=0;
        int j=0;
        int minwindowsize=INT_MAX;
        int start_i=0;
        int required_count=t.length();
        while(j<n){
            char ch=s[j];
            if(mp[ch]>0){
                required_count--;
            }
                mp[ch]--;
            while(required_count==0){
                //start shrinking the window
                int currWindowSize=j-i+1;
                if(minwindowsize>currWindowSize){
                    minwindowsize=currWindowSize;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                required_count++;
                i++;
            }
            j++;
        }
        return minwindowsize==INT_MAX?"":s.substr(start_i,minwindowsize);
    }
};