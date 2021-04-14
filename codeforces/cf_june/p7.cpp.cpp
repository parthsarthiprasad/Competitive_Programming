//simple dp approach to find bottom up approach

#include<bits/stdc++.h>
using namespace std;

void generateSubsets(int n){
    int range = (1<<length) -1;
    for(int i=0;i<=range;i++){

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int p,q,r,a,b,c;
      long diff[4];
      long ratio[4];
      cin>>p>>q>>r;
      cin>>a>>b>>c;
      ratio[0] = a*1.0/p;
      ratio[1] = b*1.0/q;
      ratio[2] = c*1.0/r;
      ratio[3] = max(ratio[0], max(ratio[1],ratio[2]));
      diff[0] = a-p;
      diff[1] = b-q;
      diff[2] = c-r;
      diff[3] = max(diff[0],max(diff[1],diff[2]));
      //all cases of doing in 0 tries
      bool ans=true;
      int diffcount=0;
      for(int i=0;i<2;i++){
          if(diff[i]==0||ratio[i]==1){
              continue;
          }
          else{
              ans=false;
          }

          if((diff[i]==diff[i+1])||ratio[i]==ratio[i+1]){
              continue;
          }
          else{
              diffcount++;
          }
      }

      if(ans){
          cout<<0<<endl;
          continue;
      }
      if(diffcount==1){
          cout<<1<<endl;
      }

     
    }
    return 0;
}