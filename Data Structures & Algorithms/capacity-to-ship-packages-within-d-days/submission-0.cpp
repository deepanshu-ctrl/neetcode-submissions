class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int ans=*max_element(w.begin(),w.end());
        while(true){
            int s=1, cap=ans;
            for(int x:w){
                if(cap-x<0){
                s++;
                cap=ans;
                }
                cap-=x;
            }
            if(s<=days) return ans;
            ans++;
        }
    }
};