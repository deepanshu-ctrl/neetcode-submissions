class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX,l=0,c=0;
        for(int i=0;i<nums.size();i++){
            c+=nums[i];
            while(c>=target){
                ans=min(ans,i-l+1);
                c-=nums[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};