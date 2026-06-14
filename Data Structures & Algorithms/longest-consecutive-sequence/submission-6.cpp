class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(auto x:nums){
            int l1=1;
            while(st.find(x+l1)!=st.end()) {l1++;}
            ans=max(ans,l1);
        }
        return ans;
    }
};
