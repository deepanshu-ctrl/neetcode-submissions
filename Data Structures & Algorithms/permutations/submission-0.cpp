class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>pick(nums.size(),false);
        vector<int> sb;
        solve(sb,nums,pick);
        return ans;
    }
    void solve(vector<int> &sb,vector<int> &nums,vector<bool> &pick){
        if(sb.size()==nums.size()){
            ans.push_back(sb);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!pick[i]){
                sb.push_back(nums[i]);
                pick[i]=true;
                solve(sb,nums,pick);
                sb.pop_back();
                pick[i]=false;
            }
        }
    }
};
