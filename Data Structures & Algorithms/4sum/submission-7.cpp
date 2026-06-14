class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if (i> 0 && nums[i] == nums[i- 1]) continue;
            for(int j=i+1;j<n-2;j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k=j+1,r=n-1;
                while(k<r){
                    long long s = 1LL * nums[i] + nums[j] + nums[k] + nums[r];
                    if(s==target) {st.insert({nums[i],nums[j],nums[k],nums[r]}); k++; r--;
                    while (k < r && nums[k] == nums[k - 1]) k++;
                    while (k < r && nums[r] == nums[r + 1]) r--;}
                    else if(s>target) r--;
                    else k++;
                }
            }
        }
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};