class Solution {
public:
    bool ispal(string s){
        int  l=0, r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return ispal(s.substr(0,l)+(s.substr(l+1)))||
                ispal(s.substr(0,r)+(s.substr(r+1)));
            }
            l++; r--;
        }
        return true;
    }
};