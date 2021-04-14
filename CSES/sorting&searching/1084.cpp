#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int solve(){
 int n,m,k;
 cin>>n>>m>>k;
 int ptr[n], b[m];
 for(int i=0;i<n;i++) cin>>ptr[i];
 for(int i=0;i<m;i++) cin>>b[i];
 sort(ptr,ptr+n);
 sort(b, b+m);
 int num = 0;
 for(int i=0, j=0;i<m && j<n;){
     if(b[i]-k <= ptr[j] && b[i]+k >= ptr[j]){
         i++;
         j++;
         num++;
     }else if(b[i]-k <=ptr[j]){
         i++;
     }else{
         j++;
     }
 }
 return num;   
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<"\n";
    return 0;
}
/*
https://cses.fi/problemset/task/1084
*/