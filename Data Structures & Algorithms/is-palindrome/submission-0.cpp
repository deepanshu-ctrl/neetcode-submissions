class Solution {
public:
    bool isPalindrome(string s) {
        string ns="";
        for(char x:s){
            if(isalnum(x)){
                ns+=tolower(x);
            }
        }
        return ns==string(ns.rbegin(),ns.rend());
    }
};
