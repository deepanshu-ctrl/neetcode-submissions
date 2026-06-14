class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
        int l=0,r=1;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int p=prices[r]-prices[l];
                mp=max(p,mp);
            }
            else{
                l=r;
            }
            r++;
        }
        return mp;
    }
};
