#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n,u,r,d,l;
       cin>>n>>u>>r>>d>>l;
       bool possible = true;
       if(u==0 && l==n){
           possible = false;
       }
       if(u==0 && r==n){
           possible = false;
       }
       if(d==0 && l==n){
           possible = false;
       }
       if(d==0 && r==n){
           possible = false;
       }
       if(u==0 && d==0 && l>n-2){
           possible = false;
       }
       if(u==0 && d==0 && r>n-2){
           possible = false;
       }
       
       swap(u,l);
       swap(d,r);
       if(u==0 && d==0 && l>n-2){
           possible = false;
       }
       if(u==0 && d==0 && r>n-2){
           possible = false;
       }
        if(u==0 && l==n){
           possible = false;
       }
       if(u==0 && r==n){
           possible = false;
       }
       if(d==0 && l==n){
           possible = false;
       }
       if(d==0 && r==n){
           possible = false;
       }
       
       if(u==0 && d==0 && l>n-2){
           possible = false;
       }
       if(u==0 && d==0 && r>n-2){
           possible = false;
       }
       int leftblocks=0;
       if(u==0){
           if(d==0){
               if(r==0){
                   if(l==0) leftblocks=0;
                   else leftblocks = n-2;
               }else{
                   if(l==0) leftblocks=n-2;
                   else leftblocks=2*n-4;
               }
           }else{
               if(r==0){
                   if(l==0) leftblocks=n-2;
                   else leftblocks = 2*n-3;
               }else{
                   if(l==0) leftblocks=2*n-3;
                   else leftblocks=3*n-4;
               }
           }
       }else{
            if(d==0){
               if(r==0){
                   if(l==0) leftblocks=n-2;
                   else leftblocks = 2*n-3;
               }else{
                   if(l==0) leftblocks=2*n-3;
                   else leftblocks=3*n-4;
               }
           }else{
               if(r==0){
                   if(l==0) leftblocks=2*n-4;
                   else leftblocks = 3*n-4;
               }else{
                   if(l==0) leftblocks=3*n-4;
                   else leftblocks=4*n-4;
               }
           }
       }
       
       if(u+r+d+l> leftblocks){
           possible=false;
       }
       if(possible)cout<<"YES\n";
       else cout<<"NO\n";
    }
}