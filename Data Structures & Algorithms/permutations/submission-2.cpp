class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> &temp,int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(temp[i],temp[j]);
            solve(nums,temp,i+1);
            swap(temp[i],temp[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp=nums;
        solve(nums,temp,0);
        return ans;
    }
};
