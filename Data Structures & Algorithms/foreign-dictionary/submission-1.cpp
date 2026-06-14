class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_set<int>st;
        for(auto x:words){
            for(auto i:x) st.insert(i);
        }
        int n=st.size();
        unordered_map<char,int> ci;
        unordered_map<int,char> ic;
        int idx=0;
        for( auto x: st){
            ci[x]=idx;
            ic[idx]=x;
            idx++;
        }
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int len=min(w1.length(),w2.length());
            if(w1.length()>w2.length() && w1.substr(0,len)==w2){
                return "";
            }
            for(int j=0;j<len;j++){
                if(w1[j]!=w2[j]){
                    int u=ci[w1[j]];
                    int v=ci[w2[j]];
                    adj[u].push_back(v);
                    ind[v]++;
                    break;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        string ans="";
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans+=ic[f];
            for(auto x:adj[f]){
                ind[x]--;
                if(ind[x]==0) q.push(x);
            }
        }
        return ans.length()==n?ans:"";
    }
};
