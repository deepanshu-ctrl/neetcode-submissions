class Solution {
public:
    int s=0;
    // void solve(vector<int>&nums,int i,int ct){
    //     if(i==nums.size()){
    //         s+=ct; return;
    //     }
    //     solve(nums,i+1,ct^nums[i]);
    //     solve(nums,i+1,ct);
    // }
    int solve(vector<int>&nums,int i,int ct){
        if(i==nums.size()) return ct;
        return solve(nums,i+1,ct^nums[i])+solve(nums,i+1,ct);
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};