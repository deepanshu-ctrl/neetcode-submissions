class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        for(auto x:s){
            v[x-'a']++;
        }
        for(auto x:t){
            v[x-'a']--;
        }
        for(auto x:v){
            if(x) return false;
        }
        return true;
    }
};
