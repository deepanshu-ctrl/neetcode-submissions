class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int n,int k,int x,vector<int> &temp){
        if(x==k){
            ans.push_back(temp);
            return;
        }
        if(x>k||temp.size()>k||i>n) return;
        temp.push_back(i);
        i+=1;
        x+=1; 
        solve(i,n,k,x,temp);
        temp.pop_back(); i--; x--;
        solve(i+1,n,k,x,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,n,k,0,temp);
        return ans;
    }
};