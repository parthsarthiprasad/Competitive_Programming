#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
struct points{
    int x;
    int y;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
       vector<points> vec(n);
       rep(i,0,n){
          cin>>vec[i].x;
          cin>>vec[i].y;
       }
    
       bool possible = false;
       rep(i,0,n){
           bool tempos = true;
           rep(j,0,n){
               if(i==j) continue;
               if((abs(vec[i].x - vec[j].x) + abs(vec[j].y - vec[i].y))>k) tempos = false;
           }
           possible = possible || tempos;
       }
       if(possible){
           cout<<1<<endl;
       }else{
           cout<<-1<<endl;
       }

      


       


    }
    return 0;
}