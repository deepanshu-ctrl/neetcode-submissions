class LRUCache {
public:
    int cap;
    vector<pair<int,int>> c;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        for(int i=0;i<c.size();i++){
            if(c[i].first==key){
                pair<int,int> temp=c[i];
                c.erase(c.begin()+i);
                c.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0;i<c.size();i++){
            if(c[i].first==key){
                c.erase(c.begin()+i);
                c.push_back({key,value});
                return;
            }
        }
        if(c.size()==cap) c.erase(c.begin());
        c.push_back({key,value});
    }
};
