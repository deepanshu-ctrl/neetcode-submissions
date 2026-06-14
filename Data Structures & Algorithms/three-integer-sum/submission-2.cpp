class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int s=0;
        set<vector<int>> v;
        while(s<n-1){
            int k=s+1;
            int l=n-1;
            while(k<l){
                if(nums[s]+nums[k]+nums[l]==0) v.insert({nums[s],nums[k++],nums[l--]});
                else if(nums[s]+nums[k]+nums[l]>0) l--;
                else k++;
            }
            s++;
        }
        for(auto &x:v){
            ans.push_back(x);
        }
        return ans;
    }
};
