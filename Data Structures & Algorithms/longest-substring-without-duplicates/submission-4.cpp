class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int l=0;
        vector<int> cnt(1001,0);
        for(int i=0;i<s.size();i++){
            cnt[s[i]]++;
            while(cnt[s[i]]>1) cnt[s[l++]]--;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};