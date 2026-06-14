class Solution {
public:
    // int solve(vector<int> &nums,int i,int j){
    //     if(i==nums.size()) return j;
    //     return solve(nums,i+1,j^nums[i])+solve(nums,i+1,j);
    // }
    int ans=0;
    void solve(vector<int> &nums,int i,int j){
        ans+=j;
        for(int k=i;k<nums.size();k++){
            solve(nums,k+1,j^nums[k]);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        solve(nums,0,0);
        return ans;
    }
};