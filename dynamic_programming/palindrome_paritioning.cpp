#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;
    int n = a.size();
    int dp[n+1][n+1];
    for(int i=0;i<n;i++){
        dp[i][0] = i;
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++) dp[i][i] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<n-i;j++){
            if(a[j-1]==a[j+i-1]){
                dp[j][i]= dp[j-1][i-1];
            }else{
                dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<< dp[n][n];
    return 0;
}