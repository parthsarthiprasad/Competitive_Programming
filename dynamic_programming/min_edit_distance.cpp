// minimum edit distance
#include<bits/stdc++.h>
using namespace std;
void solve(){
    // 3 operations , edit , delete add
    string a, b;
    cin>>a>>b;
    int n = sizeof(a);
    int m = sizeof(b);
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)dp[i][0]=i;
    for(int j=0;j<=m;j++)dp[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min( dp[i-1][j-1],
                                min(dp[i-1][j],
                                    dp[i][j-1])
                              )+1;
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}