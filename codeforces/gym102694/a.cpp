#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5+1;
vector<int> G[nax];
pair<int,int> dfs(int src, int parent=-1, int distance = 0){
    pair<int,int> res = {distance,src};
    for(auto a:G[src]){
        if(a!=parent) res = max(res, dfs(a,src,distance+1));
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    pair<int,int> p = dfs(0,-1);
    p = dfs(p.second,-1);
    cout<<p.first*3<<endl;
    return 0;
}