class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mpp;
        int x=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()) x=max(x,mpp[s[i]]+1);
            mpp[s[i]]=i;
            ans=max(ans,i-x+1);
        }
        return ans;
    }
};