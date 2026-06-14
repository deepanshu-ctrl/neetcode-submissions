class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,ans=INT_MAX,t=0;
        for(int r=0;r<nums.size();r++){
            t+=nums[r];
            while(t>=target){
                ans=min(ans,r-l+1);
                t-=nums[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};