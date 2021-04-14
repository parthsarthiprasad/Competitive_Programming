//count of subsets to a given sum
#include<bits/stdc++.h>
using namespace std;

int fincount(int ptr[], int n,int k){
    int dp[n+1][k+1];
    for(int i=0;i<=k;i++) dp[0][i]=0;
    for(int i=0;i<=n;i++) dp[i][0]= 1;
    for(int i=1; i<=n;i++){
        for(int j=1;j<=k;j++){
            if(ptr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-ptr[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][k];

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    cout<<fincount(ptr,n,k);
    return 0;
}