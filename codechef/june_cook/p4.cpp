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

pair<int, int> bfs(int u, vector<vector<int> >adj) 
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
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        {    
            int v = *it; 
            if (dis[v] == -1) 
            { 
                q.push(v); 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
    int maxDis = 0; 
    int nodeIdx=u; 

    for (int i = 0; i < n; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 

    return make_pair(nodeIdx, maxDis); 
}

void bfsi(int u, vector<vector<int> >adj, vector<ll> &ans){
    int dis[n]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u); 
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        int t = q.front();       q.pop(); 
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it; 

            if (dis[v] == -1) 
            { 
                q.push(v); 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
    
 
   
    //  get farthest node distance and its index 
     int psize = sizeof(primes)/sizeof(primes[0]);

    for (int i = 0; i < n; i++) 
    {   
        for(int j=0;j<psize;j++){
            if ( dis[i]!=0 && (dis[i]+1)%primes[j]==0) 
        { 
            ans[i] = ans[i]*primes[j];
           
        } 
     }
        
    } 
    return ; 
}
void solve(){
    cin>>n;
    vector<vector<int> > adj(n);

    vector<ll> ans(n,1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
   

   
    //this is the node at the edge of diameter of the node;

     //pair<int,int> startingnode = bfs(0,adj);
    //  cout<<startingnode.first<<startingnode.second;
    //bfsi(startingnode.first, adj, ans);
    for(int i=0;i<n;i++){
        bfsi(i,adj,ans);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }    
    cout<<endl;
    return ;

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