#include<bits/stdc++.h>
using namespace std;
int findskipcost(int ptr[], int dp[],int start, int end){
    if(start>end) return 0;
    if(dp[start]!=-1) return dp[start];
    int cost = INT_MAX;
    int cost1 = ptr[start]==0?0:1;
    int cost2 = start<=end && ptr[start+1]==0? cost1: cost1+1;
    cost = min({cost1 + findskipcost(ptr, dp, start+2,end),
                cost1 + findskipcost(ptr, dp, start+3,end),
                cost2 + findskipcost(ptr, dp, start+3,end),
                cost2 + findskipcost(ptr, dp, start+4,end)});
    return dp[start] = cost;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ptr[n];
        int dp[n];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;++i) cin>>ptr[i];
        cout<< findskipcost(ptr, dp, 0,n-1)<<endl;
    }
}