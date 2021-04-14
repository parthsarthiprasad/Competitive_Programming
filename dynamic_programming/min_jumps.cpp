#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long 
#define mp make_pair
#define pb push_back
using namespace std;
int recursol(int ptr[], int i, int n){
    if(i>=n) return 0;
    if(ptr[i]==0) return INT_MAX;
    int val= INT_MAX;
    for(int j=1;j<=ptr[i];j++){
        val = min(val, recursol(ptr,i+j,n));
    }
    return val;
}
int dpsol(int* ptr,int i,int n){
    int dp[n];
    for(int i=0;i<n;i++){dp[i] = INT_MAX;}
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=ptr[i] && j<n;j++){
            dp[j] = min(dp[j], dp[i]+1);
        }
    }
    for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    cout<<endl;
    return dp[n-1];
}
ll solve(){
    int n;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    //return recursol(ptr,0,n);
    return dpsol(ptr,0,n);
}
int main(){
    fio
    int t;
    cin>>t;
    while(t--){
    cout<<solve()<<endl;
    }
    return 0;
}