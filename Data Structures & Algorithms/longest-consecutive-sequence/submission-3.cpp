class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int l=0;
        for(int n:st){
            if(st.find(n-1)==st.end()){
                int l1=1;
                while(st.find(n+l1)!=st.end()){
                    l1++;
                }
                l=max(l,l1);
            }
        }
        return l;
    }
};
