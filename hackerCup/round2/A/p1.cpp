#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define pb push_back
#define mp make_pair
#define ll long long 
#define int long long
void weirdinput(vector<pair<ll,ll> > &L, int k, int n, int w){
    ll temp,a,b,c,d;
    for(int i=0;i<k;i++){
        cin>>temp;
        L.pb(mp(temp,temp+w));
    }
    cin>>a>>b>>c>>d;
    for(int i=k;i<n;i++){
        ll num = a*(L[i-2].first)+b*(L[i-1].first) + c ;
        num%=d;
        num++;
        L.pb(mp(num, num+w));
    }
}
void display(vector<pair<ll,ll> > vec){
    for(auto a:vec){
        cout<<a.first<<" "<<a.second<<endl;
    }
}
int solve(){
    int n,k,w, temp;
    cin>>n>>k>>w;
    vector<pair<ll,ll> > L,H;
    weirdinput(L,k,n,w);
    weirdinput(H,k,n,w);
    //display(L);
    //display(H);
    vector<int> perimeter(n,0);
    perimeter[0] = 2*(w+H[0].first);
    for(int i=1;i<n;i++){
        perimeter[i] = perimeter[i-1] + w*(w+H[i].first) - 2*(max(0LL,L[i-1].second - L[i].first));
        if(L[i-1].second - L[i].first >0)
        perimeter[i]-=2*(min(H[i-1].first, H[i].first));
        //length[i] = L[i] .first - (L[i-1].second) + L[i].second;
    }

    long long  ans = 1;
    for(int i=0;i<n;i++){
        ans*=perimeter[i];
        ans%=mod;
    }
    return ans;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<endl;
    }
    return 0;
}