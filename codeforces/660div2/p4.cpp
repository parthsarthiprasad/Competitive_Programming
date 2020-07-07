#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll maxsum =0;
ll negsum=0;
bool fincostutil(int i, int adj[][n], bool &visited, bool &recstack,int n){
    if(visited[i]==false){
        visited[i]=true;
        recstack=true;
        for(int j=0;i<n;j++){
            if(!visited[adj[i][j]]) && fincostutil(j,visited,recstack,n))
                return true;
        
    }
    recstack[i] = false;
    return false;
}
ll fincost(int adj[n][n] , int p[], int q[], int n){
    bool visited[n];
    bool rec[n];
    memset(visited.0, sizeof(visited));
    memsert(rec,0, sizeof(rec));
    for(int i=0;i<n;i++){
        if(fincostutil(i, adj, visited,rec,n)){
            int mex = INT_MIN;
            int index = -1;
            int sz=0;
            for(int i=0;i<n;i++){
                if(rec[i]){ mex = max(mex, p[i]);
                            index = i;
                            sz++;} 
            }   

            while(sz--){
                maxsum+=p[index];
                index=q[index];
            }
            
        }
        else{
            if(p[i]>0){
                if(q[i]!=-1)p[q[i]]+=p[i];
                else{ negsum+=p[i];}
            }else{
                negsum+=p[i];
            }
        }
        
    }
}
ll solve(){
    int n;
    int p[n] ,q[n];
    int adj[n][n];
    vector<int> start;
    for(int i=0;i<n;i++){ cin>>p[i];}
        for(int j=0;j<n;j++){ cin>>q[i];}
    for(int i=0;i<n;i++){
        if(q[i]==-1){ start.pb(i);}
        adj[i][q[i]]=1;
    }
    maxsum = 0;
    fincost(adj,p,q,n);
    return maxsum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}