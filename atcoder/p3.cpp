//understand and complete this

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5+1;
int dp[N] , a[N], b[N], c[N];
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
    dp[index] =val;
    return dp[index];
}
ll solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=0;i<n;i++) dp[i] = -1;
    return findrecur(0,true,true,true,n);
    
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

