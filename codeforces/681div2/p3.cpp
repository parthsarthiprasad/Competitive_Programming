#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
pair<long long int,long long int> findans(vector<int> &a, vector<int> &b, int i,int n, vector<pair<long long int,long long int>> &dp,long long int maxinter=0){
    if(i>=n ) return {0,maxinter};
    if(dp[i].first != -1) return dp[i];
    long long int count1 = 0, count2 = 0;
    count1 = findans(a,b,0,i-1,dp,maxinter).first + a[i] + findans(a,b,i+1,n,dp,maxinter).first;
    count2 = max(maxinter,max(findans(a,b,i+1,n,dp,maxinter).second, findans(a,b,0,i-1,dp,maxinter).second));
    pair<long long int,long long int>counta =   findans(a,b,0,i-1,dp,max(maxinter,(long long int)b[i]));
    pair<long long int,long long int>countb =   findans(a,b,i+1,n, dp,max(maxinter,(long long int)b[i]));
    maxinter = max(maxinter, max((long long int)b[i], max(counta.second, countb.second)));
    pair<long long int, long long int> answer;
    if( max(count1,count2) < max(counta.first + countb.first, maxinter )){
        answer.first = count1;
        answer.second = count2;
    }else{
        answer.first = counta.first + countb.first ;
        answer.second = maxinter;
    }
    return dp[i] = answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<pair<long long int,long long int >> dp(n,{-1,-1});
        long long int answer = max(findans(b,a,0,n,dp).first, findans(b,a,0,n,dp).second);
        // for(auto a:dp){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        // cout<<endl;
        cout<<answer<<endl;
    }
    return 0;
}