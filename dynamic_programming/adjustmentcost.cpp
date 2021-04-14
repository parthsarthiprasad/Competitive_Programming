#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> ptr(n);
    for(int i=0;i<n;i++) cin>>ptr[i];
    //brute force approach
    //assuming all elements are less than 100
    int dp[n+1][100];
    memset(dp,100000,sizeof(dp));
    for(int i=0;i<100;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<100;j++){
            for (int t = max(j-t,0); k <= min(100,j+t); t++) 
                dp[i][j] = min(dp[i][j], dp[i - 1][t] + abs(ptr[i-1] - j)); 
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<100;i++){
        ans = min(ans,dp[n][i]);
    }
    cout<<ans<<endl;

}