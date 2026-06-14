class Solution {
public:
    void merge(vector<int> &nums,int s,int m,int l,vector<int> &temp){
        int i=s,j=m+1,k=s;
        while(i<=m && j<=l){
            if(nums[i]<=nums[j]) temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }
        while(i<=m) temp[k++]=nums[i++];
        while(j<=l) temp[k++]=nums[j++];
        for(int i=s;i<=l;i++) nums[i]=temp[i];
    }
    void msort(vector<int> &nums,int s,int l,vector<int>&temp){
        if(s>=l) return;
        int m=s+(l-s)/2;
        msort(nums,s,m,temp);
        msort(nums,m+1,l,temp);
        merge(nums,s,m,l,temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        msort(nums,0,n-1,temp);
        return nums;
    }
};