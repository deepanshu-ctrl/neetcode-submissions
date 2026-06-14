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
        v[0]=0;v[1]=1;v[2]=1;
        for(int i=3;i<=n;i++){
            v[i]=v[i-1]+v[i-2]+v[i-3];
        }
        return v[n];
        // return solve(v,n);
    }
};