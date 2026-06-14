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
        v[0]=1,v[1]=1;
        for(int i=2;i<=n;i++){
            v[i]=v[i-1]+v[i-2];
        }
        return v[n];
        // return solve(v,n);
    }
};
