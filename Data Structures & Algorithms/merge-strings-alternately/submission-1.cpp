class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=word1.size();
        int l2=word2.size();
        int mini=min(l1,l2);
        int i=0;
        string ans="";
        while(i<mini){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }
        if(l1<l2){
            ans+=word2.substr(i);
        }
        else{
            ans+=word1.substr(i);
        }
        return ans;
    }
};