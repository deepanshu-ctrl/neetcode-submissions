class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,cs=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(auto x:nums){
            cs+=x;
            int d=cs-k;
            ans+=mpp[d];
            mpp[cs]++;
        }
        return ans;
    }
};