class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(auto x:nums){
            int s=0,c=x;
            while(st.find(c)!=st.end()) {s++; c++;}
            ans=max(ans,s);
        }
        return ans;
    }
};
