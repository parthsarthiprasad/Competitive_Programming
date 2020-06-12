#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void solve(){
    int n;
    cin>>n;
    ll x=0,y=0;
    bool flag=true;
    cin>>x>>y;
    for(int i=1;i<4*n-1;i++){
        int a,b;
        cin>>a>>b;
        x=x^a;
        y=y^b;
    }
    cout<<x<<" "<<y<<endl;
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}