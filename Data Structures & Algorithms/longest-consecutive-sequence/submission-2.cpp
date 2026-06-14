class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int ans=0, c=nums[0], s=0,i=0;
        while(i<nums.size()){
            if(c!=nums[i]){
                c=nums[i];
                s=0;
            }
            while(i<nums.size() && nums[i]==c){
                i++;
            }
            c++;
            s++;
            ans=max(ans,s);
        }
        return ans;
    }
};
