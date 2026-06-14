class Solution {
public:
    void rev(vector<int> &nums,int s,int l){
        while(s<l){
            swap(nums[s++],nums[l--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        rev(nums,0,n-1);
        rev(nums,0,k-1);
        rev(nums,k,n-1);
    }
};