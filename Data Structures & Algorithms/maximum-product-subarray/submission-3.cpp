class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int n=nums.size(), ans=nums[0];
        // int p=0,s=0;
        // for(int i=0;i<n;i++){
        //     p=nums[i]*(p==0?1:p);
        //     s=nums[n-i-1]*(s==0?1:s);
        //     ans=max(ans,max(p,s));
        // }
        // return ans;
        int ans=nums[0];
        int cmin=1,cmax=1;
        for(auto x:nums){
            int temp=cmax*x;
            cmax=max(x,max(x*cmin,x*cmax));
            cmin=min(x,min(x*cmin,temp));
            ans=max(ans,cmax);
        }
        return ans;
        // int ans=nums[0];
        // int cmin=1, cmax=1;
        // for(auto x:nums){
        //     int temp=cmax*x;
        //     cmax=max(x,max(x*cmin,x*cmax));
        //     cmin=min(x,min(temp,x*cmin));
        //     ans=max(ans,cmax);
        // }
        // return ans;
    }
};
