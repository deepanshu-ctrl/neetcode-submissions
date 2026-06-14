class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> &temp,int i){
        ans.push_back(temp);
        if(i>nums.size()) return;
        for(int j=i;j<nums.size();j++){
            if(nums[j]==nums[j-1] && j>i) continue;
            temp.push_back(nums[j]);
            solve(nums,temp,j+1);
            temp.pop_back();
        }
        // temp.push_back(nums[i]);
        // solve(nums,temp,i+1);
        // temp.pop_back();
        // while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        // solve(nums,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,temp,0);
        return ans;
    }
};
