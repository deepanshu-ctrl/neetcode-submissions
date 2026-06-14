class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1,l=0;
        while(s[i]==' ') i--;
        while(i>=0 && s[i]!=' '){
            i--; l++;
        }
        return l;
    }
};