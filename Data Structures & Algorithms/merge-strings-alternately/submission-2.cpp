class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=word1.size();
        int l2=word2.size();
        string ans="";
        int i=0,j=0;
        while(i<l1 || j<l2){
            if(i<l1) ans.push_back(word1[i++]);
            if(j<l2) ans.push_back(word2[j++]);
        }
        return ans;
    }
};