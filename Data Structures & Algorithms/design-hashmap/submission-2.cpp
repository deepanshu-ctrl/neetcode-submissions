class MyHashMap {
public:
    vector<int>v;
    vector<bool> p;
    MyHashMap() {
        v.resize(1000001,0);
        p.resize(1000001,false);
    }
    
    void put(int key, int value) {
        v[key]=value;
        p[key]=true;
    }
    int get(int key) {
        return p[key]?v[key]:-1;
    }
    
    void remove(int key) {
        p[key]=false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */