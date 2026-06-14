class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int>&v){
        if(i>=nums.size()) return 0;
        if(v[i]!=-1) return v[i];
        int t=nums[i]+solve(nums,i+2,v);
        int nt=solve(nums,i+1,v);
        return v[i]=max(t,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+1,-1);
        return solve(nums,0,v);
    }
};
