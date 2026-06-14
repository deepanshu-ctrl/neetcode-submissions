class Solution {
public:
    int arrangeCoins(int n) {
        if(n<=3) return n==1?1:n-1;
        long long l=1,r=(n/2)+1,ans=0;
        while(l<r){
            long long m=l+(r-l)/2;
            long long c=(m*(m+1LL))/2;
            if(c<=n) l=m+1;
            else r=m;
        }
        return l-1;
    }
};