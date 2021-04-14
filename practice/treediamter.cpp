#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5+1;
vector<int> G[nax];
pair<int,int> dfs(int src, int parent=-1, int value = 0){
    pair<int,int> tempans = {value,src};
    for(auto a:G[src]){
        if(a!=parent){
            tempans = max(tempans, dfs(a,src,value+1));
        }
    }
    return tempans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)G[n].clear();
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    pair<int,int> ans = dfs(0);
    ans = dfs(ans.second);
    cout<<ans.first<<endl;
}