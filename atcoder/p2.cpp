#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5+1;
int dp[N] , a{N}, b{N}, c{N};
int findrecur(int index, bool i,bool j, bool k , int n){
    if(index==n) return 0;
    int val = INT_MIN;
    if(dp[index]!=-1) return dp[index];
    if(i)
    val = max(val, findrecur(index+1,false,true,true,n) + a[index]);
    if(j)
    val = max(val, findrecur(index+1,true,false,true,n) + b[index]);
    if(k)
    val = max(val, findrecur(index+1,true,true,false,n) + c[index]);
    return dp[index] = val;
}
ll solve(){
    int n;
    cin>>n;
    for(auto x: a) cin>>x;
    for(auto x: b) cin>>x;
    for(auto x: c) cin>>x;
    memset(dp, -1 , n*sizeof(int));
    int ans = findrecur(0,true,true,true,n);
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

