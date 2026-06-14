class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int n=nums.size();
        while(i<=n){
            int m=i+(n-i)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target) n=m-1;
            else i=m+1;
        }
        return -1;
    }
};
