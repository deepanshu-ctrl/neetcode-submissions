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
        if(n==0) return 0;
        if(n==1) return nums[0];    
        vector<int> v(n+2,0);
        for(int i=n-1;i>=0;i--){
            int tk=nums[i]+v[i+2];
            int nt=v[i+1];
            v[i]=max(tk,nt);
        }
        return v[0];
        // for(int i=0;i<nums.size();i++){
        //     int tk=nums[i]+v[i+2];
        //     int nt=v[i+1];
        //     v[i]=max(tk,nt);
        // }
        // return v[n-1];
        // return solve(nums,0,v);
    }
};
