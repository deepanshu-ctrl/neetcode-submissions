class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        int maxi=0;
        int mult=1;
        while(l<r){
            int mini=min(heights[l],heights[r]);
            mult=(r-l)*mini;
            if(heights[l]>heights[r]) r--;
            else l++;
            maxi=max(maxi,mult);
        }
        return maxi;
    }
};
