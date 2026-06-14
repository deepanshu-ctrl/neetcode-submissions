class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0,y=0;
        int n=nums.size();
        for(int i=0;i<=n;i++){
            x=x^i;
        }
        for(int i=0;i<n;i++) y=y^nums[i];
        return x^y;
    }
};
