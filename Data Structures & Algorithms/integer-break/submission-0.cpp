class Solution {
public:
    map<pair<int,int>,int>mpp;
    int solve(int n,int i){
        if(mpp.find({n,i})!=mpp.end()) return mpp[{n,i}];
        if(min(n,i)==0) return 1;
        if(i>n) return solve(n,n);
        return mpp[{n,i}]=max(i*solve(n-i,i),solve(n,i-1));
    }
    int integerBreak(int n) {
        // mpp[1]=1;
        return solve(n,n-1);
    }
};