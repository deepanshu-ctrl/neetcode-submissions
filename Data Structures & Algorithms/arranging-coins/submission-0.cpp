class Solution {
public:
    int arrangeCoins(int n) {
        int r=0;
        while(n-r>0){
            r++;
            n-=r;
        }
        return r;
    }
};