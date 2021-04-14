#include<bits/stdc++.h>
using namespace std;
#define int int64_t
const int nax = 5e5;
vector<int> G[nax];
bool possible;
void dfs(vector<bool> &visited, vector<bool>& deb,int src, int parent = -1, bool depth = false){
    if(visited[src]==true){
        if(deb[src]!=depth){
            possible = false;
             cout<<"here"<<deb[src]<<" "<<src<<depth<<endl;
        }
        return;
    }
    visited[src] = true;
    deb[src] = depth;
    for(auto a:G[src]){
    
        if(visited[a]==true){
            if(deb[a]==depth) possible=false;
        }
        dfs(visited, deb,a,src,!depth);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        possible = true;
        for(int i=0;i<=n;i++)G[i].clear();
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<bool> depth(n,false);
        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i]== false){
                count++;
                dfs(visited,depth,i);
            }
        }
        cout<<count<<" "<<possible<<endl;
    }
    return 0;
}