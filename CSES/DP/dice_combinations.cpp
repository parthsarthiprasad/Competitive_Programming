#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mod = 1e9+7;
    ll n;
    cin>>n;
    vector<int> ptr(n+1,0);
    ptr[0]=1;
    for(ll i=0;i<=n;i++){
        for(ll j=1;j<7 && i+j<=n;j++)
            (ptr[i+j]+=ptr[i])%=mod;
    }
    cout<<ptr[n]<<endl;
    return 0;
}