//tree diameter
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int nax = 2e5+1;
vector<int> G[nax];
vector<int> ans;

pair<int,int> dfs(int src, int parent=-1, int distance = 0){
    pair<int,int> res = mp(distance,src);
    ans[src] = max(ans[src], distance);
    for(auto a: G[src]){
        if(a!=parent){
            res = max(res, dfs(a,src, distance+1));
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,a,b;
    cin>>n;
    ans = vector<int>(n);
    ans.clear();
    for(int i=1;i<n;i++){
        cin>>a>>b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    pair<int,int> bm = mp(0,0);
    for(int i=0;i<3;i++){
    bm = dfs(bm.second, -1);
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" "; cout<<endl;
    return 0;
}