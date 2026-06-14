class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m=1;
        int cz=0;
        for(auto x:nums){
            if(x) m*=x;
            else cz++;
        }
        int n=nums.size();
        vector<int> ans(n,0);
        if(cz>1) return ans;
        else if(cz==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0) ans[i]=m;
            }
            return ans;
        }
        else{
            for(int i=0;i<n;i++){
                ans[i]=m/nums[i];
            }
            return ans;
        }
    }
};
