class Solution {
public:
    int solve(vector<int> &v,int n){
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        if(v[n]!=-1) return v[n];
        return v[n]=solve(v,n-1)+solve(v,n-2)+solve(v,n-3);
    }
    int tribonacci(int n) {
        vector<int>v(n+1,-1);
        return solve(v,n);
    }
};