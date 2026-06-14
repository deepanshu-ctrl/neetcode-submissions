class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m=1;
        int cz=0;
        vector<int> v(nums.size(),0);
        for(auto x:nums){
            if(x==0){
                cz++;
                continue;
            }
            m*=x;            
        }
        if(cz>1) return v;
        if(cz==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]){
                    v[i]=0;
                }
                else v[i]=m;
            }
            return v;
        }
        else{
            for(int i=0;i<nums.size();i++){
                v[i]=m/nums[i];
            }
            return v;
        }
    }
};
