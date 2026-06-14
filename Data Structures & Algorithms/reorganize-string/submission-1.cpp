class Solution {
public:
    string reorganizeString(string s) {
        vector<int> f(26);
        for(auto x:s) f[x-'a']++;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++) if(f[i])pq.push({f[i],i+'a'});
        string ans="";
        while(pq.size()>1){
            auto [c1,a]=pq.top(); pq.pop();
            auto [c2,b]=pq.top(); pq.pop();
            ans+=a; ans+=b;
            if(--c1) pq.push({c1,a});
            if(--c2) pq.push({c2,b});
        }
        if(!pq.empty()){
            if(pq.top().first>1) return "";
            ans+=pq.top().second;
        }
        return ans;
    }
};