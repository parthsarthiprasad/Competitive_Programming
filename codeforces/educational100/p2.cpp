#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
void dfs(int x,int y, int left, bool movx, set<pair<int,int>> &s){
    if(left==0){
        s.insert({x,y});
        return ;
    }
    if(movx){
        dfs(x,y+1,left-1,false,s);
        dfs(x,y-1,left-1,false,s);
    }else{
        dfs(x-1,y,left-1,true,s);
        dfs(x+1,y,left-1,true,s);
    }
}
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        for(int i=1;i<=1000;i++){
            int n = i;
            set<pair<int,int>> s;
        dfs(1,0,n-1,true,s);
        dfs(-1,0,n-1,true,s);
        dfs(0,-1,n-1,false,s);
        dfs(0,1,n-1,false,s);
        cout<<i<<" "<<s.size()<<endl;
        }

    }
    return 0;
}

/*
1 4
2 4
3 12
4 9
5 24
6 16
7 40
8 25
9 60
10 36
11 84
12 49
13 112
14 64
15 144
16 81
17 180
18 100
19 220
20 121
21 264
22 144
23 312
24 169
25 364
26 196
27 420
28 225
29 480

*/