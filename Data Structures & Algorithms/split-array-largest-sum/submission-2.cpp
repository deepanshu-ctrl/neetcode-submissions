class Solution {
public:
    bool cs(vector<int> &nums,int k,int l){
        int sb=1,cs=0;
        for(auto x:nums){
            cs+=x;
            if(cs>l){
                sb++;
                if(sb>k) return 0;
                cs=x;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            if(cs(nums,k,m)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};