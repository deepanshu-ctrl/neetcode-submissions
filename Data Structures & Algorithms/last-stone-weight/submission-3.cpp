class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>hp;
        for(auto x:stones) hp.push(x);
        while(hp.size()>1){
            int f=hp.top();
            hp.pop();
            int s=hp.top();
            hp.pop();
            if(s<f) hp.push(f-s);
        }
        hp.push(0);
        return hp.top();
    }
};
