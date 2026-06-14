class Solution {
public:
    // int solve(vector<int> &nums,int i,int j){
    //     if(i==nums.size()) return j;
    //     return solve(nums,i+1,j^nums[i])+solve(nums,i+1,j);
    // }
    int subsetXORSum(vector<int>& nums) {
        // return solve(nums,0,0);
        int ans=0;
        for(auto x:nums){
            ans|=x;
        }
        return ans<<(nums.size()-1);
    }
};