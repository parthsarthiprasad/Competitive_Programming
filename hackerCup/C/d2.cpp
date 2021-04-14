#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF =(ll) 1e9+5; 
ll findrecur(ll ptr[], ll dp[], int index, int pass, int n){
    //if(index<0) return INF;
    if(index<=0) return 0;
    if(dp[index]!=INF) return dp[index];
    else{
        ll val= INF;
        for(int i=1;i<=pass && index-i>=0;i++){
            val = min(val, ptr[index-i] + findrecur(ptr,dp,index-i, pass,n));
        }
        return dp[index] = val;
    }
}
ll solve(){
    int n,m;
    cin>>n>>m;
    ll ptr[n];
    for(int i=0;i<n;i++) {
        cin>>ptr[i];
        if(ptr[i]==0) ptr[i] = INF;
    
    }
    //maximise distance with the fuel and cost
    //state of dp is a 2d array
    /*
    dp[i][j] represents the cost of travelling till ith city
            j represents the
    for(int i=0;i<m;i++) 
    dp[i][j] = min(dp[i-1][j] + ptr[i-1], dp[i-2][j] + ptr[i-m].. dp[i-m][j])
     dp[n];
     */
     ll dp[n+1];
     for(int i=0;i<=n;i++) dp[i] = INF;
     return findrecur(ptr,dp,n-1,m,n);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        printf("Case #%d: %lld\n",i++,solve());
    }
    return 0;
}