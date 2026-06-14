class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int l=0, maxi=0,ans=0;
        for(int r=0;r<s.size();r++){
            mpp[s[r]]++;
            maxi=max(maxi,mpp[s[r]]);
            while((r-l+1)-maxi>k) mpp[s[l++]]--;
            ans=max(ans,r-l+1);
        }
        return ans; 
    }
};
