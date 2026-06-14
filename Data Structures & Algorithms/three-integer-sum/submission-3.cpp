class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int s=0;
        set<vector<int>> st;
        for(int i=0;i<n-1;i++){
            int k=i+1;
            int l=n-1;
            while(k<l){
                s=nums[i]+nums[k]+nums[l];
                if(s==0) {st.insert({nums[i],nums[k],nums[l]}); k++; l--;}
                else if(s>0) l--;
                else k++;
            }
        }
        for(auto x:st) ans.push_back(x);
        return ans;
        return ans;
    }
};
