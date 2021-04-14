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
       int count = 0;
        vector<bool> rows(n,false), cols(n,false);
        vector<pair<int,int>> points;
        bool cycle = false;
       for(int i=0;i<m;i++){
           count++;
           int a,b;
           cin>>a>>b;
           a--;b--;
           if(a==b){
               count--;
           }
           if(rows[a]==true || cols[b]==true){
            cycle = true;
           }
           rows[a] = true;
           cols[b] = true;   
           cols[a] = true;
       }
    //    cout<<cycle<<" ";
       cout<<count + int(cycle)<<"\n";

    }
    return 0;
}