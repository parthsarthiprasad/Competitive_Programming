#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int ptr[n];
    for(auto &a:ptr) cin>>a;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;++j){
            if(j==0){
                dp[i][j]=1; continue;
            }
            dp[i][j] = 0;
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(ptr[i-1]=='0'){
            for(int j=1;j<=m;j++){
                dp[i][j] = 1+ (j>0?dp[i-1][j-1]:0) + dp[i-1][j] +
                           (j<m?dp[i-1][j+1]:0); 
            }
            // dp[i][j] = (ptr[i]>0?dp[i-1][ptr[i]-1]:0) + (ptr[i]<m?dp[i-1][ptr[i]+1]:0)
            //             + dp[i-1][ptr[i]];
        }
        else{
            for(int j:{ptr[i-1]}){
                dp[i][j] = (j>0?dp[i-1][j-1]:0) + dp[i-1][j] +
                           (j<m?dp[i-1][j+1]:0); 
            }
        }
    }
    int count = 0;
    for(int i=1;i<=m;i++){
        count+=dp[n][m];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<count<<endl;
    return 0;

}