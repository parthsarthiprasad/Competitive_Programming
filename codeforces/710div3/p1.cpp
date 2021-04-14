#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,x;
        cin>>n>>m>>x;
        int r = (x-1)/n;
        int c = (x-1)%n;
        int ans = c*m + r;
    
        // int ans = x*m + x%m;
        cout<<1+ans<<endl;

    }
}