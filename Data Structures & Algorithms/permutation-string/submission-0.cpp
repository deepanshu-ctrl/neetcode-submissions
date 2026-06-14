class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mpp;
        for(auto x:s1) mpp[x]++;
        int n=mpp.size();
        for(int i=0;i<s2.size();i++){
            unordered_map<char,int> mpp2;
            int c=0;
            for(int j=i;j<s2.length();j++){
                char ch=s2[j];
                mpp2[ch]++;
                if(mpp[ch]<mpp2[ch]) break;
                if(mpp[ch]==mpp2[ch]) c++;
            }
            if(c==n) return true;
        }
        return false;
    }
};
