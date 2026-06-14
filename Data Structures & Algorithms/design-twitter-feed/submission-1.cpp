class Twitter {
public:
    int cnt;
    unordered_map<int,vector<vector<int>>> tm;
    unordered_map<int,set<int>> fm;
    Twitter() {
        cnt=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tm[userId].push_back({cnt++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        auto compare=[](const vector<int> &a,const vector<int> &b) {
            return a[0]<b[0];
            };
        priority_queue<vector<int>,vector<vector<int>>, decltype(compare)>mh(compare);
        fm[userId].insert(userId);
        for(auto x:fm[userId]){
            const vector<vector<int>> &tweets=tm[x];
            if(tweets.empty()) continue;
            int idx=tweets.size()-1;
            mh.push({tweets[idx][0],tweets[idx][1],x,idx});
        }
        while(!mh.empty() && ans.size()<10){
            vector<int> cur=mh.top();
            mh.pop();
            ans.push_back(cur[1]);
            int idx=cur[3];
            if(idx>0){
                const vector<int>&t=tm[cur[2]][idx-1];
                mh.push({t[0],t[1],cur[2],idx-1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fm[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fm[followerId].erase(followeeId);
    }
};
