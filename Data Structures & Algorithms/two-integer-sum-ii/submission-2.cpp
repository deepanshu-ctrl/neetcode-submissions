class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<numbers.size();i++){
            int temp=target-numbers[i];
            if(mpp.count(temp)) return{mpp[temp],i+1};
            mpp[numbers[i]]=i+1;
        }
        return {};
    }
};
