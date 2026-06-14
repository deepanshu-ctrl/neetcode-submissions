class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> &sb,vector<bool> &pick){
        if(nums.size()==sb.size()){
            ans.push_back(sb);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(pick[i]||(i>0 && nums[i]==nums[i-1] && !pick[i-1])) continue;
            pick[i]=true;
            sb.push_back(nums[i]);
            solve(nums,sb,pick);
            pick[i]=false;
            sb.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> sb;
        sort(nums.begin(),nums.end());
        vector<bool>pick(nums.size(),false);
        solve(nums,sb,pick);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};