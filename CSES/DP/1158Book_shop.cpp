#include<bits/stdc++.h>
using namespace std;
int h[1000], s[1000];
int n,x;
void input(){
    for(int i=0;i<n;i++) cin>>h[i];
    for(int j=0;j<n;j++) cin>>s[j];
    return ;
}
//classic knapsack
int solve(){
    cin>>n>>x;
    input();
    int dp[n+1][x+1];
    for(int i=0;i<=n;i++){ dp[i][0] = 0;}
    for(int j=0;j<=x;j++){ dp[0][j] = 0;}
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if( j>=h[i-1])
                dp[i][j] = max(dp[i-1][j], 
                               dp[i-1][j-h[i-1]] + s[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][x];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<endl;
}
/*
4 10
4 8 5 3
5 12 8 1
*/