#include<bits/stdc++.h>
using namespace std;
bool valid(int i,int j,int a,int b){
    if(i<0 || i>=a || j<0 || j>=b) return false;
    return true;
}
int dirx[4] = {0,0,-1,1};
int diry[4] = {-1,1,0,0};
void dfs(vector<vector<bool> > &visited, string t[], int i, int j , int a, int b){
    visited[i][j] = true;
    for(int k=0;k<4;k++){
        if(valid(i+dirx[k], j+diry[k],a,b) && visited[i+dirx[k]][j+diry[k]] == false){
            dfs(visited,t,i+dirx[k],j+diry[k], a,b);
        }
    }
    return ;

}
int main(){
    int a,b;
    cin>>a>>b;
    string t[a];
    for(int i=0;i<a;i++){
        cin>>t[i];
    }
    vector<vector<bool> > visited(a,vector<bool> (b,false));
    int count = 0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(t[i][j]=='#') visited[i][j] = true;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(visited[i][j]==false){
                count++;
                dfs(visited,t,i,j,a,b);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}