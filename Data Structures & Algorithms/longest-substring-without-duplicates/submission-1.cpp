class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int x=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end() && mpp[s[i]]>=i-x){
                x=i-mpp[s[i]];
            }
            else x++;
            ans=max(ans,x);
            mpp[s[i]]=i;
        }
        return ans;
    }
};