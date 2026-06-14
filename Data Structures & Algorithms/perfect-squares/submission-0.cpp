class Solution {
public:
    unordered_map<int,int>mpp;
    int solve(int n){
        if(n==0) return 0;
        if(mpp.count(n)) return  mpp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i));
        }
        return mpp[n]=ans;
    }
    int numSquares(int n) {
        return solve(n);
    }
};