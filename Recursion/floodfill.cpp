#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long 
#define mp make_pair
#define pb push_back
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
void floodfill(int **ptr,int x,int y,int m,int n,int k, int val){
    if(x<0 || x>=m || y<0 || y>=n) return;
    if(ptr[x][y]==val) 
    {   ptr[x][y]=k;
        for(int i=0;i<4;i++){
            floodfill(ptr,x+dirx[i],y+diry[i],m,n,k,val);
        }
    }
    return;
}
void solve(){
    int n,m;
    cin>>n>>m;
    int **ptr = new int*[n];
    for(int i=0;i<n;i++){
        ptr[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ptr[i][j];
        }
    }
    int x,y,k;
    cin>>x>>y>>k;
    floodfill(ptr,x,y,n,m,k, ptr[x][y]);
    for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++){
            cout<<ptr[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}
int main(){
    fio
    int t;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}