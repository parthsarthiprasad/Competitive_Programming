/*
https://practice.geeksforgeeks.org/problems/rotten-oranges/0/
*/
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long 
#define mp make_pair
#define pb push_back
using namespace std;
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,1,-1};
bool valid(int newx,int newy,vector<vector<int>> &mat, int r, int c){
    if(newx<0 || newy<0 || newx == r || newy == c || mat[newx][newy]!=1) return false;
    return true;
}
ll solve(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    
    queue<pair<int,int>> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==2){
                q.push({i,j});
            }
        }
    }
    int count = -1;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            pair<int,int> temp = q.front();
            q.pop();
            for(int j=0;j<4;j++){
                int newx = temp.first+dirx[j];
                int newy = temp.second + diry[j];
                if(valid(newx,newy,mat,r,c)){
                    mat[newx][newy]=2;
                    q.push({newx,newy});
                }
            }
        }
        count++;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==1) return -1;
        }
    }
    return count;
    
}
int main(){
    fio
    int t;
    cin>>t;
    while(t--){
    cout<<solve()<<endl;
    }
    return 0;
}