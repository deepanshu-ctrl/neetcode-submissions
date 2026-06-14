class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i=0;
        int j=0;
        for(auto x:nums){
            if(j==0){
                i=x;
            }
            j+=(x==i)?1:-1;
        }
        return i;
    }
};