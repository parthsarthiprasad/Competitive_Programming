// https://www.codechef.com/EGMA2020/problems/XORARY
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
const int nax = 17;
int64_t dp[nax][1<<nax];
vector<int> a(nax),b(nax);
int64_t rec(int index, int64_t mask, int n){
    if(index==n) return 0;
    if(dp[index][mask]!=-1) return dp[index][mask];
    for(int i=0;i<n;i++){
        if((mask & (1ll<<i))==0){
            dp[index][mask] = max(dp[index][mask],(a[index] ^ b[i]) + rec(index+1, mask | (1ll<<i) ,n));
        }
    }
    return dp[index][mask];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];

    // for(auto &k:a)cin>>k;
    // for(auto &k:b)cin>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1ll<<n);j++) dp[i][j] = -1;
    }
    // memset(dp,-1,sizeof(dp));
    cout<<rec(0,0ll,n)<<"\n";
    return 0;
    
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<(1ll<<n);j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    
    // for(int i=0;i<n;i++)
    // for(int j=0;j<(1<<n);j++){
    //     int temp = 0;
    //     while(1<<temp <=j){
    //         if((1<<temp & j)==0){
    //             dp[i][j| (1<<temp)] = max(dp[i][j|(1<<temp)], dp[i-1][j] + a[i]^b[temp]);
    //         }
    //         temp++;
    //     }
    //     if(((1<<i) & j)==0)
    // int answer = 0;
    // for(int i=0;i<n;i++){
    //     answer = max(answer, dp[i][1ll<<n]);
    // }
    // cout<<answer<<endl;

        
}