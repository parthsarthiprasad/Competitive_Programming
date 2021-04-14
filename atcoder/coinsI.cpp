//coins
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    double ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    double dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    //dp[i][j] represents the probaility of i heads , when j coins are tossed
    for(int coin =0; coin<n; ++coin){
        for(int i=coin+1;i>-1;--i){
            dp[i] = (i==0 ? 
                    0: dp[i-1] * ptr[coin]) + dp[i] *(1-ptr[coin]);
        }
    }

    double sum=0;
    //for(int i=0;i<n;i++) cout<<dp[i]<<" "; cout<<endl;
    for(int i=n-(n)/2;i<=n;i++) sum+=dp[i];
    //printf("%10lf\n", sum);
    cout<< setprecision(11);
    cout<<sum<<endl;
    return 0;

}

/*
5
0.42 0.01 0.42 0.99 0.42
*/