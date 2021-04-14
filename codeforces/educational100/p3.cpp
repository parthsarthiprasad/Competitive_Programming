#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
constexpr  unsigned64_t gcd( unsigned int64_t u,  unsigned int64_t v){
    if (u == v || u == 0 || v == 0)
        return u | v;

    // effectively compute min(ctz(u), ctz(v))
    unsigned shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    v >>= __builtin_ctz(v);

    const auto &[min, max] = std::minmax(u, v);

    return gcd(max - min, min) << shift;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<  unsigned int64_t> a(n);
        vector<  unsigned int64_t> b(m);
        rep(i,0,n)cin>>a[i];
        rep(i,0,m)cin>>b[i];
        
        for(int i=0;i<m;i++){
             unsigned int64_t ans = a[0] + b[i];
            for(int j=1;j<n;j++)
            // ans = gcd(ans, a[j] + b[i]);
            ans = __gcd(ans,a[j] + b[i] );
            cout<<ans<<" ";
        }
        cout<<"\n";



    }
    return 0;
}