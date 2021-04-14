#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mod = 1e9+7;
    cout<<mod<<endl;
    int len = n-sizeof(s);
    ll ans=1;
    while(len--){
        (ans*=26)%=mod;
    }
    (ans*=(n-sizeof(s)+1))%=mod;
    cout<<ans<<"\n";
    return 0;
}