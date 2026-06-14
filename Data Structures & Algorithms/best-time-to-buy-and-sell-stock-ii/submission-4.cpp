class Solution {
public:
    int solve(vector<int> &p,int i,bool b){
        if(i==p.size()) return 0;
        int ans=solve(p,i+1,b);
        if(b){
            ans=max(ans,p[i]+solve(p,i+1,false));
        }
        else ans=max(ans,-p[i]+solve(p,i+1,true));
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        // return solve(prices,0,false);
        int mp=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) mp+=prices[i]-prices[i-1];
        }
        return mp;
        // int mp=0;
        // for(int i=1;i<prices.size();i++){
        //     if(prices[i]>prices[i-1]) mp+=prices[i]-prices[i-1];
        // }
        // return mp;
    }
};