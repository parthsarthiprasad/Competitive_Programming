#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5+1;
const int mod = 1e9+7;
vector<int> G[nax];
int64_t dfs(int src, int leftvaults,bool ispossible, int k, vector<vector<int64_t>>&dp,
            int m, int parent = -1){
    if(leftvaults<0) return 0;
    if(dp[src][leftvaults]!=-1) return dp[src][leftvaults];

    int64_t &count = dp[src][leftvaults];
    count = 0;
    bool leaf = true;
    for(auto a:G[src]){
        if(a!=parent){
            leaf = false;
            if(ispossible){
                count += (m-1)*dfs(a,leftvaults,true,k,dp,m,src);
                count%=mod;
                count += dfs(a,leftvaults-1,false,k,dp,m,src);
                count%=mod;
            }else{
                count+= (k-1)*dfs(a,leftvaults, true,k,dp,m,src);
                count%=mod;
            }

        }
    }
    if(leaf){
        if(ispossible){
            count = m;
        }else{
            count = k-1;
        }

    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)G[i].clear();
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int k,  x;
    cin>>k>>x;
    vector<vector<int64_t>> dp(n,vector<int64_t>(x+1,-1));  
    cout<<dfs(0,x,true,k, dp,m)<<"\n";
     for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }


}