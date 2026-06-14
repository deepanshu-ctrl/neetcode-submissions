class Solution {
public:
    int solve(vector<int> &nums,int t){
        int s=0, l=nums.size()-1;
        int i=nums.size();
        while(s<=l){
            int m=s+(l-s)/2;
            if(nums[m]>=t){
                l=m-1;
                i=m;
            }
            else s=m+1;
        }
        return i;
    }
    bool isMajorityElement(vector<int>& nums, int target) {
        int s=solve(nums,target);
        return s+nums.size()/2<nums.size() && nums[s+nums.size()/2]==target;
    }
};
