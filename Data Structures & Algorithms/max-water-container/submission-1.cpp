class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0;
        int l=0,r=h.size()-1;
        while(l<r){
            int a=min(h[l],h[r])*(r-l);
            ans=max(ans,a);
            if(h[l]>=h[r]) r--;
            else l++;
        }
        return ans;
    }
};
