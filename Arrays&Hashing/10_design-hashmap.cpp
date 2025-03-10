class MyHashMap {
    public:
        map<int,int>mpp;
        MyHashMap() {
           
        }
        
        void put(int key, int value) {
            mpp[key]=value;
        }
        
        int get(int key) {
            auto it = mpp.find(key);
            if(it!=mpp.end()){
                return it->second;
            }else return -1;
    
        }
        
        void remove(int key) {
            mpp.erase(key);
        }
    };
    
    
     