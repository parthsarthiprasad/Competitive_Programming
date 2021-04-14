#include<bits/stdc++.h>
using namespace std;
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,1,-1};
char pos[4] = {'L','R','D','U'};
bool valid(int x,int y,int n,int m, vector<string>&vec){
    if(x<0 || x>=n || y<0 || y>=m || vec[x][y]=='#')return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<vector<int>> visited(n,vector<int>(m,-1));
    int startx, starty;
    int endx, endy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]=='A'){
                startx=i;
                starty=j;
            }
            if(vec[i][j]=='B'){
                endx=i;
                endy=j;
            }
        }
    }
    swap(startx,endx);
    swap(endy, endy);
    int dist =0;
    queue<pair<int,int>> q;
    q.push({startx,starty});

    while(!q.empty() && visited[endx][endy]==-1){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            auto tempr = q.front();
            q.pop();
            int tempx = tempr.first;
            int tempy = tempr.second;
            visited[tempx][tempy] = dist;
            for(int j=0;j<4;j++){
                int newx = tempx + dirx[j];
                int newy = tempy + diry[j];
                if(valid(newx,newy,n,m,vec) && visited[newx][newy]==-1){
                    visited[newx][newy] = dist+1;
                    q.push({newx,newy});
                }
            }
        }
        dist++;
    }
    bool possible = (visited[endx][endy]!=-1);
    if(possible){
        cout<<"YES\n";
        string ans;
        while(endx!=startx && endy!=starty){
            for(int i=0;i<4 && !(endx==startx && endy==starty);i++){
                int newx = endx + dirx[i];
                int newy = endy + diry[i];
                if(valid(newx,newy,n,m,vec)&& visited[newx][newy]+1==visited[startx][starty]){
                    ans.push_back(pos[i]);
                    endx=newx;
                    endy=newy;
                }
            }
        }
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }else{
        cout<<"NO\n";
    }

    
}