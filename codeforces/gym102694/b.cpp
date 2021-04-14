#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5+1;
vector<int> G[nax];
vector<int> distancefind(nax);
pair<int,int> dfs(int src, int parent=-1, int dist = 0){
    pair<int,int> res = {dist,src};
    distancefind[src] = max(distancefind[src], dist);
    for(auto a:G[src]){
        if(a!=parent) res = max(res, dfs(a,src,dist+1));
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        distancefind[i] = 0;
    }
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    pair<int,int> p = dfs(0,-1);
    p = dfs(p.second,-1);
    p = dfs(p.second,-1);
    int ans = *max_element(distancefind.begin(), distancefind.end());
    for(int i=0;i<n;i++){
        cout<<max(ans,distancefind[i]+1)<<endl;
    }
    return 0;
}