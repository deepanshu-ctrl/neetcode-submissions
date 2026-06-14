class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int s=0,l=nums.size()-1;
        while(s<=l){
            int m=s+(l-s)/2;
            if(m-1<0 || nums[m-1]!=nums[m] && (m+1==nums.size()||nums[m]!=nums[m+1])) return nums[m];
            int ls=(m-1>=0 && nums[m-1]==nums[m]?m-1:m);
            if(ls%2==1) l=m-1;
            else s=m+1;
        }
        return -1;
    }
};