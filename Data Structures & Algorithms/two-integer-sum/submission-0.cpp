class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=target-nums[i];
            if(mpp.find(l)!=mpp.end()) return {mpp[l],i};
            mpp[nums[i]]=i;
        }
        return {};
    }
};
