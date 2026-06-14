class TimeMap {
public:
    unordered_map<string,unordered_map<int,vector<string>>> ks;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ks[key][timestamp].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if(ks.find(key)==ks.end()) return "";
        int s=0;
        for(auto &[time, _]:ks[key]){
            if(time<=timestamp) s=max(s,time);
        }
        return s==0?"":ks[key][s].back();
    }
};
