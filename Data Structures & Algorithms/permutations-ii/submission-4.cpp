class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> &temp,int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<temp.size();j++){
            bool used=false;
            for(int k=i;k<j;k++){
                if(temp[k]==temp[j]){
                    used=true; break;
                }
            }
            if(used) continue;
            swap(temp[i],temp[j]);
            solve(nums,temp,i+1);
            swap(temp[i],temp[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<int> temp=nums;
        solve(nums,temp,0);
        return ans;
    }
};