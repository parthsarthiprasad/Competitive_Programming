#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long 
const int nax = 1e5+1;
const int mod = 1e9+7;
vector<int> G[nax];

int dfs(bool visited[],int src, int parent, int size=0){
    size++;
    visited[src] = true;
    int count = size;
    for(auto a:G[src]){
        if(a!=parent){
            if(visited[a]==false){
                count = max(count,dfs(visited,a,src, size));
            }
                //count=max(count,dfs(visited, a,src,size+1));
        }
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            G[i].clear();
        }
        for(int i=0;i<m;i++){
            cin>>a>>b;
            a--; b--;
            G[a].pb(b);
            G[b].pb(a);
        }

        bool visited[n];
        int count =0;
        ll numways=1;
        for(int i=0;i<n;i++) visited[n]=false;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                (numways*= dfs(visited,i,-1));
                 numways = (numways+mod)%mod;
                count++;
            }
        }
        numways = (numways+mod)%mod;
        cout<<count<<" "<<numways<<"\n";

    }
}