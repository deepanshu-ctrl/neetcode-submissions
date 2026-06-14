class Solution {
public:
    int t;
    vector<bool>used;
    bool solve(vector<int> &nums,int k,int cs){
        if(k==0) return true;
        if(cs==t) return solve(nums,k-1,0);
        for(int i=0;i<nums.size();i++){
            if(used[i]||cs+nums[i]>t) continue;
            used[i]=true;
            if(solve(nums,k,cs+nums[i])) return true;
            used[i]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%k) return false;
        t=s/k;
        sort(nums.rbegin(),nums.rend());
        used.assign(nums.size(),false);
        return solve(nums,k,0);
    }
};