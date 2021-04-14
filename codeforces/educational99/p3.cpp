#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
       int x,y;
       cin>>x>>y;
       if(x<y){
           cout<<x-1<<" "<<y<<endl;
       }else if(x==y){
           cout<<x-1<<" "<<x<<endl;
       }else{
           cout<<x-1<<" "<<y<<endl;
       }
    }
    return 0;
}