class Solution {
public:
    void merge(vector<int> &nums,int l,int  m,int r,vector<int> &temp){
        int i=l,j=m+1,k=l;
        while(i<=m && j<=r){
            if(nums[i]<nums[j]) temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }
        while(i<=m) temp[k++]=nums[i++];
        while(j<=r) temp[k++]=nums[j++];
        for(int x=l;x<=r;x++){
            nums[x]=temp[x];
        }
    }
    void ms(vector<int> &nums,int l,int r,vector<int> &temp){
        if(l>=r) return;
        int m=l+(r-l)/2;
        ms(nums,l,m,temp);
        ms(nums,m+1,r,temp);
        merge(nums,l,m,r,temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        ms(nums,0,nums.size()-1,temp);
        return nums;
    }
};