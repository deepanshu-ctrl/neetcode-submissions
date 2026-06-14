class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int l=target-nums[i];
            if(mpp.find(l)!=mpp.end()) return {mpp[l],i};
            mpp[nums[i]]=i;
        }
        return {};
    }
};
