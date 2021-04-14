#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      string s,p;
      cin>>s>>p;
      int count1s = 0;
          int count1p = 0;
          bool possible = true;
          for(int i=0;i<n && possible;i++){
              if(s[i]=='1')count1s++;
              if(p[i]=='1')count1p++;
              if(count1s<count1p){
                  possible = false;
              }
          }
          if(possible){
              if(count1s==count1p){
                  cout<<"Yes\n";
              }else{
                  cout<<"No\n";
              }
          }else{
              cout<<"No\n";
          }
    //   int couns[2] = {0}, countp[2]={0};
    //   for(auto a:s){
    //       couns[a-'0']++;
    //   }
    //   for(auto a:p){
    //       counp[a-'0']++;
    //   }
    //   if(couns[0]!=counp[0] || couns[1]!=counp[1]){
    //       cout<<"No\n";
    //       continue;
    //   }else{
    //       int count1s = 0;
    //       int count1p = 0;
    //       bool possible = true;
    //       for(int i=0;i<n && possible;i++){
    //           if(s[i]=='1')count1s++;
    //           if(p[i]=='1')count1p++;
    //           if(count1s<count1p){
    //               possible = false;
    //           }
    //       }
    //       if(possible){
    //           if(count1s==count1p){
    //               cout<<"Yes\n";
    //           }else{
    //               cout<<"No\n";
    //           }
    //       }else{
    //           cout<<"No\n";
    //       }
    //   }


    }
    return 0;
}