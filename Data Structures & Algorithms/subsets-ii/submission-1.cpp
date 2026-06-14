class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0,{});
        return ans;
    }
    void solve(vector<int> &nums,int i,vector<int> sb){
        if(i==nums.size()){
            ans.push_back(sb);
            return;
        }
        sb.push_back(nums[i]);
        solve(nums,i+1,sb);
        sb.pop_back();
        while(i<nums.size() && nums[i]==nums[i+1]) i++;
        solve(nums,i+1,sb);
    }
};
