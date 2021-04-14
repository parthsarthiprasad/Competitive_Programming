#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int n,w;
    scanf("%d%d", &n, &w);
    vector<ll> dp(w+1,0);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d", &a, &b);
        for(int j=w-a;j>0; --j){
            dp[j+a] = max(dp[j+a], dp[j]+b);
        }
    }
    ll answer = 0;
    for(int i=0;i<=w;++i){
        answer = max(answer, dp[i]);
    }
    printf("%lld\n", answer);
}