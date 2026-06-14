class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int m=*max_element(people.begin(),people.end());
        vector<int>cnt(m+1,0);
        for(auto x:people) cnt[x]++;
        int idx=0,i=1;
        while(idx<people.size()){
            while(cnt[i]==0) i++;
            people[idx++]=i;
            cnt[i]--;
        }
        int ans=0,l=0,r=people.size()-1;
        while(l<=r){
            int rem=limit-people[r--];
            ans++;
            if(l<=r && rem>=people[l]) l++;
        }
        return ans;
    }
};