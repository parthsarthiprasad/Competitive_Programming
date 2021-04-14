//flood fill in graph
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e3+5;
int d[N][N];
queue<pair<int,int> > Q;
bool valid(int x, int y){
    return (x>=0 && x<r) && (y>=0 && y<c);
}
int main(){
    int r,c;
    cin>>r>>c;
    pair<int,int> desti;
    memset(d,-1,sizeof(d));
    for(int i=0;i<r;i++) cin>>A[i];
    for(int j=0;j<c;j++){
        if(A{i[j]=='F'}){
            Q.push({i,j});
            //single bfs
            //since we pushed all edges in bfs with dis 0, 
            //we create a kind of implicit node, dummy node
            d[i][j]=0;
        }else if(A[i][j]=='P'){
            desti = {i,j};
            //else it's a . or a #
        }
    }

    int dx[] = {1,-1,0,0};
    int dy[]  ={0,0,1,-1};

    while(!Q.empty()){
        pair<int,int> u = q.front;
        q.pop();
        int x = u.first, y = u.second;
        for(int i=0;i<4;i++){
            if(valid(x + dx[i], y + dy[i]) && (d[x + dx[i]][y+dy[i]]==-1)){
                d[x+dx[i]][y+dy[i]] = d[x][y]+1;
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }

    cout<<d[desti.first][desti.second]<<"\n";
}