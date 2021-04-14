#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int N = 1e5+1;
vector<int> G[N];
vector<int> Grev[N];
int maxlen = 0;
pair<int,int> dfs(vector<int> T[],bool visited[], int src, int parent=-1,  int dist=0){
    pair<int,int> res = mp(dist+1,src);
    visited[src]=true;
    for(auto a:T[src]){
        if(a ==parent){ continue;}
        res = max(res, dfs(T, visited, a,src,dist+1));
        
    }
    return res;
}
int main(){
    int n,m,a,b;
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        Grev[b].pb(a);
    }
    //grev is the reverse graph
    //g is the actual graph
    bool visited[n];
    int len=0;
    for(int i=0;i<n;i++) visited[i] = false;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            pair<int,int> p = dfs(G, visited, i,-1);
            //cout<<p.first<<" "<<p.second<<endl;
            //this pair contains 1) the length 2) the end node
            //we are trying to find the diameter of the tree
            pair<int,int> g = dfs(Grev, visited, p.second,-1);
            len = max(len,g.first);
        }
    }

    cout<< len-1<<endl;
    return 0;


}