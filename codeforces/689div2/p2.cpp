#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int64_t findcount(int i, int j, int n, int m, vector<string> & vec,
                  vector<vector<int>>&dp, vector<vector<bool>>&visited){
    if(i==n || j==m || i<0 || j<0) return 0;
    if(visited[i][j]) return dp[i][j];
    visited[i][j] = true;
    if(vec[i][j]=='*'){
        return dp[i][j] = 1 + min(findcount(i+1,j-1,n,m, vec, dp, visited),
                   min(findcount(i+1,j,n,m,vec,dp,visited),
                        findcount(i+1,j+1,n,m,vec,dp,visited)));
    }else{
        return dp[i][j] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> vec(n);
        rep(i,0,n){
            cin>>vec[i];
        }
        vector<vector<int>> dp(n, vector<int>(m,0));
        vector<vector<bool>> visited(n, vector<bool>(m,false)) ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false){
                    findcount(i,j,n,m,vec,dp,visited);
                }
            }
        }
        int64_t count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               count+=dp[i][j];
            }
        }
        cout<<count<<endl;
        // vector<vector<int>> dp(n, vector<int> (m,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int l = i;
        //         int r = j;
        //         while(l>=0 && r>=0){
        //             bool possible = true;
        //             for(int p=l,b=r, count = dp[i][j]+1;count>0 && possible && p>=0 && b<m;p--,b++, count--){
        //                 if(vec[p][b]!='*') possible = false;
        //             }
        //             if(possible){
        //                 dp[i][j]++;
        //                 r--;
        //             }else{
        //                 break;
        //             }
        //         }
        //         // if(i>0 && j>0 && vec[i-1][j-1]=='*' && vec[i][j-1]=='*' &&
        //         //     vec[i][j] =='*'){
        //         //     dp[i][j]+=min({i,j/2,dp[i-1][j-1], dp[i][j-1]});
        //         //     dp[i][j]++;
        //         //     // dp[i][j]+=dp[i][j-1];
        //         // }else if(vec[i][j]=='*'){
        //         //     dp[i][j]++;
        //         // }
                
                
        //         // if(vec[i][j]=='*'){
        //         //     dp[i][j]++;
        //         //     if((j>0 && vec[i][j-1]=='*') && (j+1<m && vec[i][j+1]=='*') &&
        //         //        (i>0 && vec[i-1][j]=='*')){
        //         //         dp[i][j]+=dp[i-1][j];
        //         //     }
        //         // }else{
        //         //     dp[i][j] = 0;
        //         // }
               
        //     }
        // }
        // int64_t count = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         // if(j>0){
        //         //     dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
        //         // }
        //         // if(j+1<m){
        //         //     dp[i][j] = min(dp[i][j], 1+ dp[i][j+1]);
        //         // }
        //         count+=dp[i][j];
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<count<<endl;
    }
    return 0;
}