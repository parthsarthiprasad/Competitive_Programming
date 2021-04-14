#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> dp(1001,0);
        dp[0] = 1;
        dp[1] = 4;
        dp[2] = 4;
        int j = 2;
        for(int i=2;i<=1000;i+=2,j++){
            dp[i] = j*j;
        }
        j=2;
        for(int i=3;i<=1000;i+=2,j++){
            dp[i] = dp[i-2] + 4*j;
        }
        
        cout<<dp[n]<<endl;

    }
    return 0;
}