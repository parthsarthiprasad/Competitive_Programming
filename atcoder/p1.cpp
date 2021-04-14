#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll solve(){
    int n,k;
    cin>>n>>k;
    int ptr[n] ;
    vector<int> dp(n,INT_MAX);
    for(int i=0;i<n;i++) cin>>ptr[i];
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j =i+1; j<i+k && j<n; j++){
            dp[j]= min(dp[j] , dp[i] + abs(ptr[i] - ptr[j]));
        }
    }
    return dp[n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}

/*
4
10 30 40 20
*/