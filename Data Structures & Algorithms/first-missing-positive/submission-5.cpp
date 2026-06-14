class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool> v(n,false);
        for(auto x:nums){
            if(x>0 && x<=n) v[x-1]=true;
        }
        for(int i=0;i<n;i++){
            if(!v[i]) return i+1;
        }
        return n+1;
    }
};