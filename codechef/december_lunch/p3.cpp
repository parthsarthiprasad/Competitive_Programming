#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;
      int charsum[26] = {0};
      for(auto a:s){
          charsum[a-'a']++;
      }
      sort(charsum,charsum+26);
      int onesleft = 0;
      int twosleft = 0;
      int count = 0;
      for(int i=0;i<26;i++){
          int val = min(onesleft,charsum[i]/2);
          count+=val;
          onesleft-=val;
          charsum[i]-=2*val;
          if(charsum[i]>2){
              count+=charsum[i]/3;
              charsum[i]%=3;
          }
          if(charsum[i]==1){
              onesleft++;
          }else if(charsum[i]==2){
              twosleft++;
          }
      }
      int val = min(onesleft,twosleft);

      count+=val;
      onesleft-=val;
      twosleft-=val;
      if(twosleft){
          count+= 2*(twosleft/3);
          twosleft%=3;
          if(twosleft==2){
              count++;
          }
      }
    
      cout<<count<<endl;
    }
    return 0;
}