#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int64_t> vec(n);
        for(auto &a:vec)cin>>a;
        vector<int64_t> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i] = vec[i];
        }
        // for(int i=0;i<n;i++){
        //     if(i+vec[i]<n){
        //         dp[i+vec[i]]= max(dp[i+vec[i]], dp[i]+ vec[i]);
        //     }
        // }
        for(int i=n-1;i>=0;i--){
            if(i + vec[i] < n)
            dp[i]+= dp[i + vec[i]];
            else{
                dp[i] = vec[i];
            }
        }
        cout<<*max_element(dp.begin(),dp.end())<<endl;

        

    }
    return 0;
}