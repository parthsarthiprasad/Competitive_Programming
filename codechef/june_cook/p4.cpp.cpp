#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
using namespace std;
int n;
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 
              23, 29, 31, 37, 41, 43, 47,
              53, 59, 61, 67, 71, 73, 79, 
              83, 89, 97};

pair<int, int> bfs(int u, vector<vector<int> >&adj) 
{ 
    int dis[n]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u); 
  
    //  distance of u from u will be 0 
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        int t = q.front();       q.pop(); 
  
        //  loop for all adjacent nodes of node-t 
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it; 
  
            // push node into queue only if 
            // it is not visited already 
            if (dis[v] == -1) 
            { 
                q.push(v); 
  
                // make distance of v, one more 
                // than distance of t 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
  
    int maxDis = 0; 
    int nodeIdx; 
  
    //  get farthest node distance and its index 
    for (int i = 0; i < V; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis); 
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > adj(n);
    vector<ll> ans(n,1);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        vec[u].pb(v);
        vec[v].pb(u);
    }
    int psize = primes.size();
    //this is the node at the edge of diameter of the node;

    int startingnode = bfs(0,adj);
    for(int i=0;i<psize;i++){
        for(int j=0;j<n;j++)
           // bfsi(startingnode,primes[i]);
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}