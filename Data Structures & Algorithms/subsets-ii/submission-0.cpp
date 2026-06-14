class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0,{});
        return vector<vector<int>>(ans.begin(),ans.end());
    }
    void solve(vector<int> &nums,int i,vector<int> sb){
        if(i==nums.size()){
            ans.insert(sb);
            return;
        }
        sb.push_back(nums[i]);
        solve(nums,i+1,sb);
        sb.pop_back();
        solve(nums,i+1,sb);
    }
};
