class Solution {
public:
    int mySqrt(int x) {
        long long s=0,l=x;
        int ans=0;
        while(s<=l){
            long long m=s+(l-s)/2;
            if(m*m>x) l=m-1;
            else if(m*m<x) {s=m+1; ans=m;}
            else return m;
        }
        return ans;
    }
};