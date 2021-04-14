#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
const int nax = 1e5+1;
const int64_t mod = 998244353;
vector<int> G[nax];
void dfs(int src, vector<bool> &visited, int j, vector<map<int,int>> &segmentsize, vector<int> &vec, int parent = -1){
    visited[src] = true;
    for(auto a:G[src]){
        if(a!=parent ){
            if(visited[a]==false){
                visited[a] = false;
                segmentsize[j][vec[a]]++;
                dfs(a,visited,src,j, segmentsize, vec, src);
            }
        }
    }
    return ;
}


int64_t findans(vector<vector<int64_t>>&dp, int n, int index, vector<int> &segmentsize,int picked, int k){
    if(picked==k) return 1;
    if(n==index) return 0;
    return (segmentsize[index]* findans(dp,n,index+1,segmentsize,picked+1,k) + 
            findans(dp,n,index+1,segmentsize,picked,k))%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n,k;
      cin>>n>>k;
      vector<int> vec(n);
      rep(i,0,n)cin>>vec[i];
      rep(i,0,n+1){
          G[i].clear();
      }
      rep(i,0,n-1){
          int u,v;
          cin>>u>>v;
          u--;v--;
          G[u].push_back(v);
          G[v].push_back(u);
      }
      vector<map<int,int>> segmentsize;
      vector<bool> visited(n,false);
      for(int i=0;i<n;i++){
          if(vec[i]==0) visited[i] = true;
      }
      int j = 0;
      for(int i=0;i<n;i++){
          if(visited[i]==false){
              segmentsize.push_back({vec[i],1});
              dfs(i,visited,j,segmentsize,vec);
              j++;
          }
        }
      
      sort(segmentsize.begin(),segmentsize.end());
      n = segmentsize.size();
      vector<vector<int64_t>> dp(n, vector<int64_t> (1<<(k+1)+1,-1));
      int64_t count = findans(dp,n,0,segmentsize,0,k+1);
      cout<<count<<endl;
        // cout<<count<<endl;
       

   
    }
    return 0;
}