#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n,m;
      cin>>n>>m;
      vector<vector<int>> vec(n ,vector<int>(m));
      rep(i,0,n){
          rep(j,0,m)cin>>vec[i][j];
      }
      unordered_map<int, unordered_map<int,int>> uset;
      rep(i,0,n){
          rep(j,0,m){
              uset[i-j][vec[i][j]]++;
          }
      }
      
      int q;
      cin>>q;
      while(q--){
          int x,y,v;
          cin>>x>>y>>v;
          x--;
          y--;
          if(vec[x][y]!=v){
          if(uset[x-y][vec[x][y]]==1){
              uset[x-y].erase(vec[x][y]);
          }else{
              uset[x-y][vec[x][y]]--;
          }
        //   uset[x-y].erase(vec[x][y]);
          vec[x][y]=  v;
          uset[x-y][v]++;
          }
          bool possible = true;
          for(auto a:uset){
              if(a.second.size()!=1){
                  possible = false;
                  break;
              }
            //   cout<<a.first<<" ";
            //   for(auto b:a.second){
            //       cout<<b.first<<" "<<b.second<<endl;
            //   }
            //   cout<<endl;
          }
          if(possible){
              cout<<"Yes\n";
          }else{
              cout<<"No\n";
          }
      }


    }
    return 0;
}