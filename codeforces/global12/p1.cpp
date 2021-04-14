#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
struct points{
    int x;
    int y;
};
int kcount = 0; 
int n;

bool ispossible(int k, int j,  vector<vector<int>>&G){
    vector<bool> visited(n, false);
       visited[0] = true;
       queue<int> q;
       q.push(0);
       int count = 0;
       bool possible = true;
       while(!q.empty()){
           int sz = q.size();
           rep(i,0,sz){
               int tp = q.front();
               q.pop();
               for(auto a:G[tp]){
                   if((a==j && tp==k) || (a==k && tp==j)) continue;
                   if(visited[a]==false){
                   q.push(a);
                   visited[a] = true;
                   }
               }
           }
            count++;
       }
      
       rep(i,0,n){
           if(visited[i]==false){
               possible = false;
           }
       }
       kcount = min(kcount,count);
       
       return possible;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>n>>k;
       vector<points> vec(n);
       rep(i,0,n){
          cin>>vec[i].x;
          cin>>vec[i].y;
       }
       kcount = INT_MAX;
       vector<vector<int>> G(n+1);
       rep(i,0,n){
           rep(j,i+1,n){
               if((abs(vec[i].x - vec[j].x) + abs(vec[j].y - vec[i].y))<=k){
                   G[i].push_back(j);
                   G[j].push_back(i);
               }
           }
       }
        bool answer = false;
       for(int i=0;i<G.size();i++){
           for(int j=0;j<G[i].size();j++){
               answer = answer || ispossible(i,G[i][j],G);
           }
       }
       
       if(answer){
           cout<<kcount-1<<endl;
       }else{
           cout<<-1<<endl;
       }


       


    }
    return 0;
}