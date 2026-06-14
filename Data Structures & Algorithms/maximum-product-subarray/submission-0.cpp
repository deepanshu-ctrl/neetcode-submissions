class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            int c=nums[i];
            ans=max(ans,c);
            for(int j=i+1;j<nums.size();j++){
                c*=nums[j];
                ans=max(ans,c);
            }
        }
        return ans;
    }
};
