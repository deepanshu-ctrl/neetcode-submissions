class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int c=stones.back()-stones[stones.size()-2];
            stones.pop_back();
            stones.pop_back();
            if(c!=0) stones.push_back(c);
        }
        return stones.empty()?0:stones[0];
    }
};
