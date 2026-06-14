class StockSpanner {
public:
    vector<int> v;
    StockSpanner() {

    }
    
    int next(int price) {
        v.push_back(price);
        int i=v.size()-2;
        while(i>=0 && v[i]<=price) i--;
        return v.size()-i-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */