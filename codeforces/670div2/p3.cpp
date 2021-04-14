#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int nax = 1e5+1;
vector<int> G[nax];
vector<int> path;
pair<int,int> dfs(int src, int parent = -1, int dist = 1){
    path.push_back(src);
    bool leaf = true;
    pair<int,int> res = {dist, src};
    for(auto a:G[src]){
        if(a!=parent){
            leaf = false;
            res = max(res, dfs(a,src, dist+1));
        }
    }
    
    if(res.first>dist){
        path.push_back(res.second);
    }
    return res;
}
void solve(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        G[i].clear();
    }
    path.clear();
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    path.clear();
    pair<int,int> t = dfs(0,-1);
    path.clear();
    t = dfs(t.second,-1);
    vector<int> temp(t.first);
    for(int i=0;i<t.first;i++){
        temp[i] = path[i];
    }
    path.clear();
    path = temp;
    for(auto a:path){
        cout<<a<<" ";
    }
    cout<<endl;
    int x1,y1;
    x1 = path[path.size()/2];
    y1 = path[(path.size()-1)/2];

    if(x1==y1){
    y1 = path[(path.size()+1)/2];
    }
    x1++;
    y1++;
    cout<<x1<<" "<<y1<<endl;
    t = dfs(x1-1,-1);
    y1 = t.second+1;
    cout<<x1<<" "<<y1<<endl;
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
    return 0;
}