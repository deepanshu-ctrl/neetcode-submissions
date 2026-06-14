class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int c=1;
        for(int i=1;i<n;i++){
            if(c==0) { ans=nums[i]; c=1; }
            else if(nums[i]==ans) c++;
            else c--;
        }
        return ans;
    }
};