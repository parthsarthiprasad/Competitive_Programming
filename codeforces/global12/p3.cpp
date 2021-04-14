#include<bits/stdc++.h>
using namespace std;

#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       vector<string> vec(n);
       rep(i,0,n)cin>>vec[i];
       int tokencount = 0;
       rep(i,0,n){
           rep(j,0,n){
               if(vec[i][j]=='X')tokencount++;
           }
       }
       int numchanges = tokencount/3;
       priority_queue<pair<int,pair<int,int>>> pq;
       rep(i,0,n){
           rep(j,0,n){
               if(vec[i][j]!='X'){
                   continue;
               }
               int count = 0;
               if(i>0 && vec[i-1][j]=='X') {
                   count++;
               }
               if(i+1<n && vec[i+1][j]=='X'){
                   count++;
               }
               if(j>0 && vec[i][j-1]=='X'){
                   count++;
                   }
                if(j+1<n && vec[i][j+1]=='X'){
                   count++;
               }
               pq.push({count,{i,j}});
           }
       }
       set<pair<int,int>> newupdates;
       while(!pq.empty() && numchanges){
           auto st = pq.top();
           pq.pop();
           if(newupdates.find(st.second)!=newupdates.end()){
               int count = 0;
               int i = st.second.first;
               int j = st.second.second;
               if(i>0 && vec[i-1][j]=='X') {
                   count++;
               }
               if(i+1<n && vec[i+1][j]=='X'){
                   count++;
               }
               if(j>0 && vec[i][j-1]=='X'){
                   count++;
                   }
                if(j+1<n && vec[i][j+1]=='X'){
                   count++;
               }
               if(count!=st.first){
                   pq.push({count,{i,j}});
                   newupdates.insert({i-1,j});
                   newupdates.insert({i-2,j});
                   newupdates.insert({i+1,j});
                   newupdates.insert({i+2,j});
                   newupdates.insert({i,j-1});
                   newupdates.insert({i,j-2});
                   newupdates.insert({i,j+1});
                   newupdates.insert({i,j+2});
                   newupdates.erase({i,j});
               }
               else {
                   
              if(i>0 && vec[i-1][j]=='X' && i+1<n && vec[i+1][j]=='X' && vec[i][j]=='X' ){
                   vec[i][j] = 'O';
                   numchanges--;
               }
                else if(j>0 && vec[i][j-1]=='X' && j+1<n && vec[i][j+1]=='X' && vec[i][j]=='X'){
                    vec[i][j] = 'O';
                   numchanges--;
                }
                newupdates.erase({i,j});
               }
           }else{
               int i = st.second.first;
               int j = st.second.second;
               if(i>0 && vec[i-1][j]=='X' && i+1<n && vec[i+1][j]=='X' && vec[i][j]=='X' ){
                   vec[i][j] = 'O';
                   numchanges--;
               }
                else if(j>0 && vec[i][j-1]=='X' && j+1<n && vec[i][j+1]=='X' && vec[i][j]=='X'){
                    vec[i][j] = 'O';
                   numchanges--;
                }
           }
       }

       for(auto a:vec){
           cout<<a<<endl;
       }


    }
    return 0;
}