class Solution {
public:
    bool isPerfectSquare(int temp) {
        long long s=0;
        long long num=temp;
        while(s<=num){
            long long m=s+(num-s)/2;
            if(m*m==temp) return true;
            else if(m*m>temp) num=m-1;
            else s=m+1;
        }
        return false;
    }
};