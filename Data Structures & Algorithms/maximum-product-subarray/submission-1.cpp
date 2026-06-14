class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int cmin=1, cmax=1;
        for(auto x:nums){
            int temp=cmax*x;
            cmax=max(x,max(x*cmin,x*cmax));
            cmin=min(x,min(temp,x*cmin));
            ans=max(ans,cmax);
        }
        return ans;
    }
};
