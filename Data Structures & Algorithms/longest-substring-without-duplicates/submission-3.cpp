class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        vector<int> cnt(1001,0);
        int j=0;
        for(int i=0;i<s.size();i++){
            cnt[s[i]]++;
            while(cnt[s[i]]>1) cnt[s[j++]]--;
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};