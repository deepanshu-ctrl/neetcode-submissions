class Solution {
public:
    int trap(vector<int>& h) {
        if(h.empty()) return 0;
        int n=h.size();
        int l=0,r=n-1;
        int lm=h[l], rm=h[r];
        int ans=0;
        while(l<r){
            if(lm<rm){
                l++;
                lm=max(lm,h[l]);
                ans+=lm-h[l];
            }
            else{
                r--;
                rm=max(rm,h[r]);
                ans+=rm-h[r];
            }
        }
        return ans;
    }
};
