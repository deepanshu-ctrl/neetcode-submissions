class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0;
        int l=s.size()-1;
        while(st<l) swap(s[st++],s[l--]);
    }
};