#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    long long int p,q;
    cin>>p>>q;
    int orp = p;
    vector<pair<int,int>> f;
    int x= q;
    int i= 2;
    while(x>1 && i*i<=x){
       int count = 0;
       while(x%i==0){
           x/=i;
       }
       if(count)f.push_back({i,count});
       i++;
    }
    if(x!=1){
        f.push_back({x,1});
    }
    int ans = p;
    for(auto x:f){
        int pr = x.first;
        int freq = x.second;
        int cnt = 0;
        
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}