#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll n;
        cin>>n;
        if(n%k ==0) cout<<1;
        else cout<<0;
    }
    cout<<endl;

    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}