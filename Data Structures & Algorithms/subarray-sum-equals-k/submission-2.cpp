class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int s=0;
        int ans=0;
        for(auto x:nums){
            s+=x;
            int lf=s-k;
            if(mpp.find(lf)!=mpp.end()) ans+=mpp[lf];
            mpp[s]++;
        }
        return ans;
    }
};