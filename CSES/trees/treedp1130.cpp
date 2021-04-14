#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long 
const int N = 2e5+1;
vector<int> G[N];
int dp[N][2];
void dfs(int i, int parent){
    vector<ll> prefix, suffix;
    int leaf =1;
    dp[i][1]=0;
    dp[i][0]=0;
    for(auto child: G[i]){
        if(child!=parent){
            leaf=0;
            dfs(child,i);
        }
    }
    if(leaf) return ;

    for(auto child:G[i]){
        if(child!=parent){
            int val = max(dp[child][0], dp[child][1]);
            dp[i][0]+= val;
            prefix.pb(val);
            suffix.pb(val);
        }
    }
    //pre calculating prefix , suffix table
    for(int j=1; i<(int)prefix.size() ; j++) prefix[j]+=prefix[j-1];
    for(int j= prefix.size()-2;j>-1;j--) suffix[j]+=suffix[j+1];
    int c=0;
    for(auto child:G[i]){
        if(child==parent) continue;
            int lval = c==0? 0: prefix[c-1];
            int rval = (c==(int)prefix.size()-1)? 0: suffix[c+1];
            dp[i][1] = max(dp[i][1] , 1+lval + rval + dp[child][0]);
            c++;
        
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,a,b;
    cin>>n;
    //for(int i=1;i<n;i++) G[i].clear();
    for(int i=1;i<n;i++){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1,0);
    cout<< max(dp[1][0], dp[1][1])<<"\n";
    return 0;
}

/*
5
1 2
1 3
3 4
3 5
*/