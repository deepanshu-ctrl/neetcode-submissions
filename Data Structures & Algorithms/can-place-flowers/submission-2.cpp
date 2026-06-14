class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl, int n) {
        // int empty=fl[0]==0?1:0;
        // for(int f:fl){
        //     if(f==1){
        //         n-=(empty-1)/2;
        //         empty=0;
        //     }
        //     else empty++;
        // }
        // n-=empty/2;
        // return n<=0;
        vector<int> f(fl.size()+2,0);
        for(int i=0;i<fl.size();i++){
            f[i+1]=fl[i];
        }
        for(int i=1;i<f.size()-1;i++){
            if(f[i-1]==0 && f[i]==0 && f[i+1]==0){
                f[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};