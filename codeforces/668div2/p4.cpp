#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5+1;
vector<int> G[nax];
int n,a,b,da,db;
void dfs(int src, vector<int> &a1, int dist,int trav, int parent=-1 ){
    if(trav==0) a1[src] = true;
    for(auto k: G[src]){
        if(a1[k]==false){
            dfs(k,a1,dist,(trav+1)%dist, src);
        }
    }

    return ;
}
string solve(){
    cin>>n>>a>>b>>da>>db;
    a--;
    b--;
    int j,k;
    for(int i=0;i<n;i++){
        G[i].clear();
    }
    for(int i=0;i<n-1;i++){
        cin>>j>>k;
        j--;
        k--;
        G[j].push_back(k);
        G[k].push_back(j);
    }
    vector<int> a1(n,false);
    vector<int> a2(n,false);
    a1[a] = true;
    a2[b] = true;
    dfs(a,a1,da,0);
    dfs(b,a2,db,0);

    for(int i=0;i<n;i++) cout<<a1[i]<<" ";
    cout<<endl;
    for(int j=0;j<n;j++) cout<<a2[j]<<" ";
    cout<<endl;
    bool ans = true;
    for(int i=0;i<n && ans;i++){
        if(a2[i]==true && a1[i]==false) ans = false;
    }
    if(ans) return "Alice";
    return "Bob";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}