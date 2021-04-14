#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mp make_pair
#define pb push_back
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first == b.first) return a.second>b.second;
    return a.first<b.first;
}

// left shift << multiply by 2
// right shift >> divide by 2

ll solve(){
    int n,a,b,k;
    cin>>n>>k;
    vector<pair<int,int> > m;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        m.pb(mp(a,b));
    }
    int t = sizeof(m);
    ll dp[t+1][k+1];
    for(int i=0;i<=t ; i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=k;i++) dp[0][i]=0;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=k;j++){
            if(j>=m[i-1].first){
                dp[i][j] = max(dp[i-1][j], 
                                dp[i-1][j-m[i-1].first] + m[i-1].second);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[t][k];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}