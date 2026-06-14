class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
        int b=prices[0];
        for(auto x:prices){
            mp=max(mp,x-b);
            b=min(b,x);
        }
        return mp;
    }
};
