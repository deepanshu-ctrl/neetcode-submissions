class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int l=*max_element(w.begin(),w.end());
        int r=accumulate(w.begin(),w.end(),0);
        int ans=r;
        while(l<=r){
            int cap=l+(r-l)/2;
            int n=1,c=0;
            for(auto x:w){
                if(c+x>cap){
                    n++; c=0;
                }
                c+=x;
            }
            if(n<=days) r=cap-1;
            else l=cap+1;
        }
        return l;
    }
};