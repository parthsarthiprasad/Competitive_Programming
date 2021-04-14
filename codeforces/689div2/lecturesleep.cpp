#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    vector<int> time(n);
    for(auto &a:vec)cin>>a;
    for(auto &a:time)cin>>a;
    vector<int64_t> timeprefix(n+1,0);
    vector<int64_t> vecprefix(n+1,0);
    for(int i=1;i<=n;i++){
        vecprefix[i]+=vecprefix[i-1] + vec[i-1];
        if(time[i-1]==0)
        timeprefix[i] = timeprefix[i-1];
        else {
            timeprefix[i] = timeprefix[i-1] + vec[i-1];
        }
    }
    vector<int64_t> dp(n+1,0);
    for(int i=0;i<k;i++){
        dp[i] = timeprefix[i];
    }
    for(int i=k;i<=n;i++){
        dp[i] = max(timeprefix[i], timeprefix[n] -(timeprefix[i] - timeprefix[i-k]) + (vecprefix[i] - vecprefix[i-k]));
    }
    cout<< *max_element(dp.begin(), dp.end())<<"\n";


}