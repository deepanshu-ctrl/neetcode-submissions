class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> w;
        int l=0;
        for(int r=0;r<nums.size();r++){
            if(r-l>k){
                w.erase(nums[l]); l++;
            }
            if(w.find(nums[r])!=w.end()) return true;
            w.insert(nums[r]);
        }
        return false;
    }
};