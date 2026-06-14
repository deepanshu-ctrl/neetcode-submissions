class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0,l=nums.size()-1;
        while(s<=l){
            int m=s+(l-s)/2;
            if(nums[m]==target) return m;
            if(nums[m]<target) s=m+1;
            else l=m-1;
        }
        return s;
    }
};