#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    int dp[13][13][10];
    bool solve(vector<vector<char>>& board, string &word,int i,int j,int idx){
        if(idx==word.size()) return true;
        if(i<0||i>=n||j<0||j>=m||word[idx]!=board[i][j]) return false;
        if(dp[i][j][idx]!=-1) return dp[i][j][idx];
        char temp=board[i][j];
        board[i][j]='#';
        bool ans=solve(board,word,i,j+1,idx+1)||
        solve(board,word,i+1,j,idx+1)||
        solve(board,word,i,j-1,idx+1)||
        solve(board,word,i-1,j,idx+1);
        board[i][j]=temp;
        return dp[i][j][idx]=ans;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        n=board.size();
        m=board[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        for(auto x:words){
            bool wf=false;
            memset(dp,-1,sizeof(dp));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(solve(board,x,i,j,0)){
                        ans.push_back(x);
                        wf=true;
                        break;
                    }
                }
                if(wf) break;
            }
            
        }       
        return ans;
    }
};
