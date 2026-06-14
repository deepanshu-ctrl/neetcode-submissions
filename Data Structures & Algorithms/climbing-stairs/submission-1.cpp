class Solution {
public:
    int solve(vector<int> &v,int n){
        if(n==0) return 1;
        if(v[n]!=-1) return v[n];
        int t1=solve(v,n-1);
        int t2=solve(v,n-2);
        return v[n]=t1+t2;
    }
    int climbStairs(int n) {
        vector<int> v(n+1,-1);
        return solve(v,n);
    }
};
