#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long 
const int mod =   1000000007;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,a,b,c;
    cin>>n;
    a=0;
    b=1;
    if(n==0) cout<<a<<endl;
    else if(n==1) cout<<b<<endl;
    else{
        for(int i=2;i<=n;i++){
            c=a+b;
            if(c>mod) c-=mod;
            a=b;
            b=c;
        }
        cout<<c<<endl;
    }
    return 0;
}