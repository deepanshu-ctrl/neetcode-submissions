class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,m=0,l=nums.size()-1;
        while(m<=l){
            if(nums[m]==0) swap(nums[s++],nums[m++]);
            else if(nums[m]==1) {m++; continue;}
            else swap(nums[m],nums[l--]);
        }
    }
};