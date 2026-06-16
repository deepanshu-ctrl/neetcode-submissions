class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int c=0;
        for(int i=0;i<nums.size();i++){
            c+=nums[i];
            if(c>maxi) maxi=c;
            if(c<0) c=0;
        }
        return maxi;
    }
};
