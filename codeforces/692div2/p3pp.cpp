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
        vector<int> rows(n,-1), cols(n,-1);
        // vector<bool> rows(n,false), cols(n, false);

        vector<bool> diagonals(n,false);
       for(int i=0;i<m;i++){
           int a,b;
           cin>>a>>b;
           a--;b--;
           if(a==b){
               count--;
           }
           diagonals[a] = true;
           diagonals[b] = true;
           
           count++;
       }
       int tempcount = 0;
       for(int i=0;i<n;i++){
           tempcount+=diagonals[i];
       }
       if(tempcount==m){
           count++;
       }
    //    if(diagonals)
       cout<<count<<endl;

    }
    return 0;
}