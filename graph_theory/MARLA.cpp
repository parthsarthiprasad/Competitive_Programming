#include<bits/stdc++.h>
using namespace std;
int numbanks = 0;
int value = INT_MAX;
int ptr[1000][1000];
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,-1,1};
void dfs(int i, int j, int n, int m, int sz ,int val){
    if(i<0 || i>=n || j<0 || j>=m || ptr[i][j]!=val) return ;
    sz++;
    if(sz>numbanks){
        value = val;
        numbanks = sz;
    }
    else if(sz==numbanks){
        value = min(value, val);
    }
    ptr[i][j] = INT_MAX;
    for(int t=0;t<4;t++){
        dfs(i+dirx[t],j+diry[t],  n,  m,  sz, val);
    }
    return ;

    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>ptr[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ptr[i][j]!=INT_MAX){
                dfs(i,j, n , m, 0, ptr[i][j]);
            }
        }
    }
    cout<<value<<" "<<numbanks<<endl;
    
}