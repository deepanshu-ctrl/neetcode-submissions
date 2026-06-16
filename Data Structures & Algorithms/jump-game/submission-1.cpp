class Solution {
public:
    int n;
    bool solve(vector<int> &nums,int i){
        if(i>=n) return true;
        if(nums[i]==0) return false;
        for(int x=1;x<=nums[i];x++){
            if(solve(nums,i+x)) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size()-1;
        return solve(nums,0);
    }
};
