class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()){
            return "";
        }
        int low=0;
        int right =mp[key].size()-1;
        if(mp[key][0].first>timestamp){
            return "";
        }
        string ans;
        while(low<=right){
            int mid =low+(right-low)/2;
            if(mp[key][mid].first==timestamp){
                return mp[key][mid].second;
            }else if(mp[key][mid].first<timestamp){
                ans=mp[key][mid].second;
                low=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */