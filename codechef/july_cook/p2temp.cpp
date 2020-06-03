#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll solve(){
    ll  n,m,x,y;
    cin>>n>>m>>x>>y;
    ll ans=0;
    ans+= (((m*n)+1)/2)* min((y+1)/2, x);
    ans+= min((y/2),x)*((n*m)/2);
   
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}