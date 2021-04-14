#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9
const int max = 5005
int D[max], N;
vector<pair<int,int> > e[max]; //adj list

void dijkstra(){
    for(int i=1;i<=N;i++) D[i] = INF;
    D[1]=0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> >> q;
    q.push({0,1});
    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;

        for(pair<int,int> pr: E[u]){
            int v = pr.first;
            int nd = dist + pr.second;
            if(nc <D[v]){
                D[v] = nd;
                q.push({nd,v});
            }
        }
    }
}