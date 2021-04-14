//minimizing coinds
//classical unbounded knapsack problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll solve(){
    int n,k;
    cin>>n>>k;
    if(k==0) return 0;
    int ptr[n], dp[k+1];
    for(int i=0;i<n;i++) cin>>ptr[i];
    sort(ptr, ptr+n);
    for(int i=0;i<=k;i++) dp[i] = 1e9;
    //for(auto v:dp) cout<<v<<" "; cout<<endl;
    dp[0]=0;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n && i-ptr[j]>-1;j++){
            dp[i] = min(dp[i], dp[i-ptr[j]] + 1);
        }
    }
    if(dp[k]==1e9) return -1;
    else return dp[k];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<"\n";

}