class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0,r=0;
        int maxi=0;
        int cnt=0;
        while(r<s.size()){
            if(mp[s[r]]) {
                mp[s[l]]--;
                l++;
                cnt--;
            }
            else {
                cnt++;
                mp[s[r]]++;
                r++;
                maxi=max(cnt,maxi);
            }
        }
        return maxi;
    }
};
