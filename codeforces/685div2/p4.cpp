#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
bool findans(unordered_map<int64_t, bool> &dist, unordered_map<int64_t,bool> &visited, 
                int64_t d,int64_t x,int64_t y, int stride){
    if( x*x + y*y > d*d) return false;
    if(x*x + y*y == d*d) return true;
    if(visited[ x*x + y*y ] == true ){
        return dist[x*x + y*y];
    } 
    dist[x*x + y*y] = false;
    dist[x*x + y*y] = (findans(dist,visited, d, x+stride,y,stride) ||
                      findans(dist,visited, d, x, y+stride, stride));
    visited[x*x + y*y] = true;
    return dist[x*x + y*y];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int64_t d,k;
       cin>>d>>k;
       unordered_map<int64_t,bool> dist;
       unordered_map<int64_t, bool> visited;
       bool ans = findans(dist, visited, d,0,0,k);
       if(ans){
           cout<<"Utkarsh\n";
       }else{
           cout<<"Ashish\n";
       }

    }
    return 0;
}