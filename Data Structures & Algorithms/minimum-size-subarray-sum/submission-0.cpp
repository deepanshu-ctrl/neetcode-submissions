class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,t=0,ans=INT_MAX;
        for(int r=0;r<nums.size();r++){
            t+=nums[r];
            while(t>=target){
                ans=min(ans,r-l+1);
                t-=nums[l];
                l++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};