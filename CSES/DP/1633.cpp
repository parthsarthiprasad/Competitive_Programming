//dice combinations
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
void findcombinations(int dp[], int n){
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<7 && i-j>-1;j++){ 
            dp[i] = (dp[i] + dp[i-j])%MOD;
        }
    }
    return ;
}
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    int dp[n+1];
    memset(dp,0,(n+1)*sizeof(int));
    dp[0]=1;
    //for(int i=0;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
    findcombinations(dp,n);
    //for(int i=0;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
    cout<<dp[n]<<"\n";
}