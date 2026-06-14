class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> pos(26);
        for(int i=0;i<26;i++){
            pos[order[i]-'a']=i;
        }
        for(int i=1;i<words.size();i++){
            string &a=words[i-1];
            string &b=words[i];
            int k=0;
            while(k<a.size() && k<b.size() && a[k]==b[k]) k++;
            if(k==b.size() && a.size()>b.size()) return false;
            if(k<a.size() && k<b.size()){
                if(pos[a[k]-'a']>pos[b[k]-'a']) return false;
            }
        }
        return true;
    }
};