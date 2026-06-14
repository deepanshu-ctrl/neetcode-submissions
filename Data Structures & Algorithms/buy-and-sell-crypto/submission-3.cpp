class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
        int a=prices[0];
        for(auto x:prices){
            mp=max(mp,x-a);
            a=min(a,x);
        }
        return mp;
    }
};
