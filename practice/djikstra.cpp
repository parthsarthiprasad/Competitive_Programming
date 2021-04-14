#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,e,a,b,w;
    cin>>v>>e;
    vector<pair<int,int>> G[v];
    for(int i=0;i<e;i++){
        cin>>a>>b>>w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    vector<int> dist(v,INF);
    dist[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({0,0});
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        if(temp.second > dist[temp.first]) continue;
        for(auto a:G[temp.first]){
            if(dist[a.first] > a.second + temp.second){
                dist[a.first] = temp.second + a.second;
                pq.push({a,temp.second+a.second});
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;
    
}