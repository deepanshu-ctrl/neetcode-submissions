class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto x:nums) mpp[x]++;
        vector<int> ans;
        vector<vector<int>> f(nums.size()+1);
        for(auto x:mpp) f[x.second].push_back(x.first);
        for(int i=f.size()-1;i>0;i--){
            for(auto x:f[i]){
                ans.push_back(x);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
