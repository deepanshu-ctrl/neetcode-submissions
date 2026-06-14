class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0,l=nums.size()-1;
        while(s<l){
            int m=s+(l-s)/2;
            if(nums[m]>nums[m+1]) l=m;
            else s=m+1;
        }
        return l;
    }
};