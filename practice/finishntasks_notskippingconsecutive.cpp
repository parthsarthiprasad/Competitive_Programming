//https://www.geeksforgeeks.org/minimum-time-to-finish-tasks-without-skipping-two-consecutive/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;++i) cin>>ptr[i];
    int dp[n+1][2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0] + ptr[i-1],dp[i-1][1] + ptr[i-1]);
    }
    for(int i=0;i<=n;i++){
        cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    cout<<min(dp[n][0], dp[n][1])<<endl;
}