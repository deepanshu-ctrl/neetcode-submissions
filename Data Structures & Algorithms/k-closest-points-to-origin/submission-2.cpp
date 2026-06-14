class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto x:points){
            int d=x[0]*x[0]+x[1]*x[1];
            pq.push({d,{x[0],x[1]}});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
        // auto comp=[] (const auto &a, const auto &b){
        // return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        // };
        // priority_queue<vector<int>,vector<vector<int>>,decltype(comp)>mh(comp);
        // for(auto x:points){
        //     mh.push({x[0],x[1]});
        // }
        // vector<vector<int>> ans;
        // for(int i=0;i<k;i++){
        //     ans.push_back(mh.top());
        //     mh.pop();
        // }
        // return ans;

        // sort(points.begin(),points.end(),
        // [] (const auto &a, const auto &b){
        //     return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        // });
        // return vector<vector<int>> (points.begin(),points.begin()+k);
    }
};
