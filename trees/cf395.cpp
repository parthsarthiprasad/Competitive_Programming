//timofry and vertex

https://codeforces.com/blog/entry/50205

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5+1;
vector<int> G[N];
vector<int> color(n+1);
int curr_colors;
bool ok;
bool dfs(int src, int parent){
    bool leaf = true;
    ok = (ok && color[src] == curr_colors);
    for(auto a: G[src]){
        if(color[a]!=color[src]){
            dfs(a,src);
        }
    }
    
}

bool solve( int v){
    int ans = true;
    for(auto a : G[v]){
        curr_colors = color[a];
        ok = true;
        dfs(a,v);
        ans = ans && ok;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }

    // now i've to pick the edges to start dfs from
    int root1 =-1, root2=-1;
    for(int i=1;i<=n;i++){
        for(auto e :g[i]){
            if(color[e]!=color[i]){
                root1=e;
                root2=i;
            }
        }
    }
    if(root1=-1){
        //no such pairs found, all olors are same
        cout<<"YES\n";
        return 0;
    }
    bool res1 = solve(root1);
    bool res2 = solve(root2);
    if(res1){
        cout<<"YES\n"<< root1;
    }
    else if(res2){
        cout<<"YES\n"<< root2;
    }
    else{
        cout<<"NO\n";
    }
    return 0;
    
}