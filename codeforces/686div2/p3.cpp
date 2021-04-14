#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    const int64_t inf=1e18;
    cin>>t;
    while(t--){
        int n,p,k;
        cin>>n>>p>>k;
        string s;
        cin>>s;
        int x,y;
        cin>>x>>y;
    
        int64_t dp[n+1] = {0};
        for(int i=n, j = k;i>0 && j>0;j--,i--){
            if(s[i-1] == '1')dp[i] = 0;
            else dp[i] = x;
        }
        for(int i=n-k;i>0;i--){
            if(s[i-1]=='1'){
                dp[i]=dp[i+k];
            }else{
                dp[i] = x+ dp[i+k];
            }
        }
       
        int64_t cost = dp[p];
        rep(i,p,n+1){
            cost = min(cost, y*(i-p) + dp[i]);
        }
        cout<<cost<<endl;


 
    }
  return 0;  
}