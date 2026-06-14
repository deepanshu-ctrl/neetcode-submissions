class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(int n:nums){
            int s=0,c=n;
            while(st.find(c)!=st.end()){
                s++; c++;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};
