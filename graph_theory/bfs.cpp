#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +5
vector<pair<int,int> > adj[N];
int d[N];

int main(){
    int n,m;
    int u,v,w;
    cin>>n>>m;
    while(m--){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    memset(d,-1,sizeof(d));
    queue<int> q;
    int src =1;
    d[src] = 0;
    q.push(src);
    while(!q.empty()){

        u = q.front();
        q.pop();
        for(auto &[v,w] : adj[u]){
            if(d[v]!=-1){
                d[v]=d[u]+1;
                q.push(v);
            }

        }
    }
}
