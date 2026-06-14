class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int c=0;
        int i=a.size()-1,j=b.size()-1;
        while(i>=0 || j>=0 || c>0){
            int da=i>=0?a[i]-'0':0;
            int db=j>=0?b[j]-'0':0;
            int tot=da+db+c;
            ans+=(tot%2)+'0';
            c=tot/2;
            i--;j--;
        }
        reverse(ans.rbegin(),ans.rend());
        return ans;\
    }
};