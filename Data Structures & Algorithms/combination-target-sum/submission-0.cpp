class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> c;
        solve(nums,target,c,0);
        return ans;
    }
    void solve(vector<int> &nums,int t,vector<int> &c,int i){
        if(t==0){
            ans.push_back(c);
            return;
        }
        if(t<0||i>=nums.size()) return;
        c.push_back(nums[i]);
        solve(nums,t-nums[i],c,i);
        c.pop_back();
        solve(nums,t,c,i+1);
    }
};
