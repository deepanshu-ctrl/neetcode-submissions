class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int k=0,i=0;
        while(i<n){
            chars[k++]=chars[i];
            int j=i+1;
            while(j<n && chars[i]==chars[j]) j++;
            if(j-i>1){
                string cnt=to_string(j-i);
                for(auto x:cnt) chars[k++]=x;
            }
            i=j;
        }
        return k;
        // string ans="";
        // int i=0;
        // while(i<n){
        //     ans+=chars[i];
        //     int j=i+1;
        //     while(j<n && chars[i]==chars[j]) j++;
        //     if(j-i>1) ans+=to_string(j-i);
        //     i=j;
        // }
        // for(int i=0;i<ans.size();i++) chars[i]=ans[i];
        // return ans.size();
    }
};