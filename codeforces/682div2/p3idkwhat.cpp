#include<bits/stdc++.h>
using namespace std;
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,1,-1};
bool valid(int x,int y, int m,int n){
     if(x<0 || y<0 || x>=n || y>=m) return false;
     return true;
}
bool dfs(int x,int y, vector<vector<int>> &vec, vector<vector<int>> &b,int n,int m){
    if(x<0 || y<0 || x>=n || y>=m) return true;
    bool possible = true;
    for(int i=0;i<4;i++){
        int newx = x + dirx[i];
        int newy = y + diry[i];
        if(valid(newx,newy,n,m) && b[newx][newy]==b[x][y]){
           
            b[newx][newy] += (b[newx][newy] == vec[newx][newy])?1:-1;
            if(!dfs(newx,newy,vec,b,n,m)){
                b[newx][newy] += (b[newx][newy] == vec[newx][newy])?1:-1;
                dfs(newx,newy,vec,b,n,m);
            }
        }
    }
    for(int i=0;i<4;i++){
        int newx = x + dirx[i];
        int newy = y + diry[i];
        if(valid(newx,newy,n,m) && b[newx][newy]==b[x][y]){
           
           possible = false;
        }
    }
    if(possible==false) b[x][y] += (b[x][y] == vec[x][y])?1:-1;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vec(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>vec[i][j];
                b[i][j] = vec[i][j];
            }
        }
        bool possible =false;
        for(int k=0;k<n && !possible;k++){
            for(int l=0;l<m && !possible;l++){
                possible = true;

                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        for(int p=0;p<4;p++){
                            int newx = i + dirx[p];
                            int newy = j + diry[p];
                            if(valid(newx,newy,n,m) && b[newx][newy]==b[i][j]){
                            possible = false;
                          }
                        }
                        if(possible==false){
                         b[i][j] += (b[i][j] == vec[i][j])?1:-1;
                         dfs(i,j,vec,b,n,m);
                    }
                    }
                    
                }
            }
        }
        for(auto a:b){
            for(auto c:a){
                cout<<c<<" ";
            }
            cout<<endl;
        }


    }
}