class Solution {
public:
    int solve(vector<int> &nums,vector<int> &v,int s,int e){
        if(s>=e)  return 0;
        if(v[s]!=-1) return v[s];
        int tk=nums[s]+solve(nums,v,s+2,e);
        int nt=solve(nums,v,s+1,e);
        return v[s]=max(tk,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> v(n+1,0),v2(n+1,0);
        for(int i=n-2;i>=0;i--){
            int tk=nums[i]+(i+2<n?v[i+2]:0);
            int nt=v[i+1];
            v[i]=max(tk,nt);
        }
        for(int i=n-1;i>=1;i--){
            int tk=nums[i]+(i+2<n?v2[i+2]:0);
            int nt=v2[i+1];
            v2[i]=max(tk,nt);
        }
        return max(v[0],v2[1]);
        // return max(solve(nums,v,0,n-1),solve(nums,v2,1,n));
    }
};
