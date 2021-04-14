//this is p2 with dp approach
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int dp[100002][6];
int n,k,z;
ll ok(int arr[], int i , int k, int z){
    if(k==0|| i>n || i<0) return 0;
    if(dp[i][z]!=-1) return dp[i][z];

    ll val = 0;
    if(i<n) val = max(val, arr[i] + ok(arr,i+1,k-1,z));
    if(i>=0 && z>0) val = max(val, arr[i] + ok(arr,i-1,k-1,z-1));
    return dp[i][z] = val;
}
ll solve(){
    cin>>n>>k>>z;
    int arr[n];
    for(int i=0;i<n; i++) cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    ll x = ok(arr,1,k,z) + arr[0];
    return x;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}
/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9

15
19
150
56
*/