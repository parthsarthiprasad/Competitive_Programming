#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
const int nax  = 2e5+5;
vector<int> G[nax];
int64_t answer ;
// int64_t dfs(int src,int endpoint=-1, int parent = -1){
//     if(src==endpoint) return 0;
//     int64_t tempans = 0;
    
//     for(auto a:G[src]){
//         if(a!=parent){
//             if(endpoint==-1)tempans+=dfs(a,endpoint,src);
//             else{
//                 tempans+=dfs(a,src,src);
//             }
//         }
//     }
//     return 1+tempans;
// }
vector<int> cyclepath;
bool dfspath(int src, int parent, vector<bool> visited){
    if(visited[src] == true){
        cyclepath.push_back(src);
        return true;
    }
    visited[src] = true;
    for(auto a:G[src]){
        if(a!=parent){
        cyclepath.push_back(a);
        if(dfspath(a,src, visited)){
            return true;
        }
        cyclepath.pop_back();
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        rep(i,0,n+1)G[i].clear();
        rep(i,0,n){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        answer = 0;
        vector<bool> visited(false);
        dfspath(0,-1,visited);
        for(auto a:cyclepath){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}