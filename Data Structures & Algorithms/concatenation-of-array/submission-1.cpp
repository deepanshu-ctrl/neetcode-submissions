class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            nums.push_back(nums[i++]);
        }
        return nums;
    }
};