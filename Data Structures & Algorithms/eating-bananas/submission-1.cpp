class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int k=l+(r-l)/2;
            long long tt=0;
            for(auto x:piles) tt+=ceil((double)(x)/k);
            if(tt<=h){
                ans=k;
                r=k-1;
            }
            else l=k+1;
        }
        return ans;
    }
};
