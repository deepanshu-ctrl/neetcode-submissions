class Solution {
public:
    bool isal(char x){
        return (x>='A' && x<='Z'||
                x>='a' && x<='z'||
                x>='0' && x<='9');
    }
    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;
        while(l<r){
            while(l<r && !isal(s[l])) l++;
            while(l<r && !isal(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
