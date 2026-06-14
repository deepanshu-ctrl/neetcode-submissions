class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans={{}};
        for(int x:nums){
            int sz=ans.size();
            for(int i=0;i<sz;i++){
                vector<int> sb=ans[i];
                sb.push_back(x);
                ans.push_back(sb);
            }
        }
        return ans;
        // vector<int> sb;
        // solve(nums,0,sb,ans);
        // return ans;
    }
    void solve(vector<int> &nums,int i,vector<int> &sb,vector<vector<int>> &ans){
        if(i>=nums.size()){
            ans.push_back(sb);
            return;
        }
        sb.push_back(nums[i]);
        solve(nums,i+1,sb,ans);
        sb.pop_back();
        solve(nums,i+1,sb,ans);
    }
};
