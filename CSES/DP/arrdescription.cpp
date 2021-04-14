#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod = 1e9+7;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int ptr[n];
    for(int i=0;i<n;++i)cin>>ptr[i];
    vector<vector<long>> dp(n+1,vector<long>(m+1,0));
    if(ptr[0]==0){
        for(int i=1;i<m+1;i++)dp[1][i] = 1;
    }else{
        dp[1][ptr[0]] = 1;
    }
    for(int i=2;i<=n;i++){
        if(ptr[i-1]==0){
            for(int j=1;j<=m;j++){
                for(int k:{j-1,j,j+1}){
                    if(k>0 && k<=m)
                    dp[i][j]+=dp[i-1][k];
                    dp[i][j]%=mod;
                }
            }
        }else{
            int j = ptr[i-1];
            for(int k:{j-1,j,j+1}){
                    if(k>0 && k<=m)
                    dp[i][j]+=dp[i-1][k];
                    dp[i][j]%=mod;
            }
        }
    
    }

    long sum = 0;
    for(int i=1;i<=m;i++){
        sum+=dp[n][i];
        sum%=mod;
    }
    cout<<sum<<endl;
    return 0;
}