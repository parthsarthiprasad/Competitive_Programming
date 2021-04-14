#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,p;
    const int64_t INF= 1e18;
    cin>>n>>k>>p;
    vector<int> vec(n), dist(k);
    for(int i=0;i<n;i++)cin>>vec[i];
    for(int j=0;j<k;j++)cin>>dist[j];
    sort(vec.begin(), vec.end());
    sort(dist.begin(), dist.end());
    vector<vector<int64_t>> dp(k+1,vector<int64_t>(n+1,INF));
    dp[0][0] = 0;
    for(int i=0;i<k;i++){
        for(int j=0;j<=n;j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] );
            if(j<n){
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(abs(p - dist[i]) + abs(dist[i] - vec[j])));
            }
        }
    }
    int64_t ans = INF;
    for(int i=0;i<=k;i++){
        ans = min(ans, dp[i][n]);
    }
    cout<<ans<<endl;

}