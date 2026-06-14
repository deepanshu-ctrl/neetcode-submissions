class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>cnt(26,0);
        for(auto x:tasks){
            cnt[x-'A']++;
        }
        priority_queue<int>mh;
        for(int x:cnt){
            if(x>0) mh.push(x);
        }
        int time=0;
        queue<pair<int,int>>q;
        while(!q.empty()||!mh.empty()){
            time++;
            if(mh.empty()){
                time=q.front().second;
            }
            else{
                int cnt=mh.top()-1;
                mh.pop();
                if(cnt>0) q.push({cnt,time+n});
            }
            if(!q.empty() && q.front().second==time){
                mh.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
