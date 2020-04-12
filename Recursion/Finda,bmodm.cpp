//find (a^b)%m where b is very large

#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll findmod(ll a,ll b,ll c ){
    ll res =1;
    a = a%c;
    while(b){
        if(b&1)
            res = (res*a)%c;
        b=b>>2;
        a=(a*a)%c;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,m;
    cin>>a>>b>>m;
    cout<<findmod(a,b,m);
    return 0;
}