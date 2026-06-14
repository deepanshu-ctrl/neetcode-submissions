class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans=0;
        for(auto x:nums){
            if(!mpp[x]){
                mpp[x]=mpp[x-1]+mpp[x+1]+1;
                mpp[x-mpp[x-1]]=mpp[x];
                mpp[x+mpp[x+1]]=mpp[x];
                ans=max(ans,mpp[x]);
            }
        }
        return ans;
    }
};
