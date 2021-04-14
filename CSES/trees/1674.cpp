#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long 
const int N = 2e5;
ll dp[N];
int dfs(int i, vector<vector<int> > &vec){
    dp[i]=1;
    for(auto j : vec[i]){
        dp[i]+=dfs(j,vec);
    }
    return dp[i];
}
void solve(){
    int n, temp;
    cin>>n;
    vector<vector<int> > vec(n+1);
    for(int i=2;i<=n;i++){
        cin>>temp;
        vec[temp].pb(i);
    }
    memset(dp,0,n+1);
    dfs(1,vec);
    for(int i=1;i<=n;i++) cout<<dp[i]-1<<" ";
    cout<<endl;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}