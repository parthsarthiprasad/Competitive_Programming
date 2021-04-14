//unbounded knapsack variation with finding all possible combinations
//different from 1634 as it tells min number of coins here i'll find all number of ways
#include<bits/stdc++.h>
using namespace std; 
const int mod = 1e9+7;
int solve(){
    int n,x;
    cin>>n>>x;
    int ptr[n] ,dp[x+1];
    for(auto &a:ptr) cin>>a;
    for(auto &b:dp) b=0;
    sort(ptr,ptr +n);
    dp[0]=1;

    for(int i=0;i<=x;i++){
        for(int j=0;j<n && i+ptr[j]<=x;j++){
            if(dp[i])(dp[i+ptr[j]]+=dp[i])%=mod;
        }
    }
    return dp[x];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<"\n";
}