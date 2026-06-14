class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        for(auto x:tasks) cnt[x-'A']++;
        priority_queue<int>pq;
        for(auto x:cnt) {
            if(x>0) pq.push(x);
        }
        int t=0;
        queue<pair<int,int>>q;
        while(!pq.empty()||!q.empty()){
            t++;
            if(pq.empty()){
                t=q.front().second;
            }
            else{
                int ct=pq.top()-1;
                pq.pop();
                if(ct>0) q.push({ct,t+n});
            }
            if(!q.empty() && q.front().second==t){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return t;
    }
};
