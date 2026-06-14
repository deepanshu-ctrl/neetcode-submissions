class Solution {
public:
    int solve(vector<int> &nums,vector<int> &v,int s,int e){
        if(s>e)  return 0;
        if(v[s]!=-1) return v[s];
        int tk=nums[s]+solve(nums,v,s+2,e);
        int nt=solve(nums,v,s+1,e);
        return v[s]=max(tk,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> v(n,-1),v2(n,-1);
        return max(solve(nums,v,0,n-2),solve(nums,v2,1,n-1));
    }
};
