#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
bool findans(map<pair<int,int>, bool> &dist, map<pair<int,int>,bool> &visited, 
                int64_t d,int64_t x,int64_t y, int stride){
    if( x*x + y*y > d*d) return false;
    if(x*x + y*y == d*d) return true;
    if(visited[{x,y}] == true || visited[{y,x}] == true){
        return dist[{x,y}] || dist[{y,x}];
    } 
    dist[{x,y}] = false;
    bool tans;
    tans = !(findans(dist,visited, d, x+stride,y,stride) && 
                      findans(dist,visited, d, x, y+stride, stride));
    dist[{x,y}] = tans;
    dist[{y,x}] = tans;
    visited[{x,y}] = true;
    visited[{y,x}] = true;
    return tans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int64_t d,k;
       cin>>d>>k;
       map<pair<int,int>,bool> dist;
       map<pair<int,int>, bool> visited;
       bool ans = findans(dist, visited, d,0,0,k);
       if(ans){
           cout<<"Utkarsh\n";
       }else{
           cout<<"Ashish\n";
       }
 
    }
    return 0;
}