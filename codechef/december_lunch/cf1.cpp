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
      int countin = 0, countout = 0;
      bool possible = true;
      if(s.size()&1) possible = false;
      for(int i=0;i<s.size();i++){
          if(s[i]=='(') countin++;
          else if(s[i]==')') countout++;
      }
      for(int i=0;i<s.size();i++){
          if(s[i]=='?'){
              if(countin<s.size()/2){
                  s[i] = '(';
                  countin++;
              }else{
                  s[i] = ')';
                  countout++;
              }
          }
      }
      countout = 0; countin = 0;
      for(int i=0;i<s.size() && possible;i++){
          if(s[i]=='(') countin++;
          else countout++;
          if(countout>countin) possible = false;
      }
      if(possible  ){
          cout<<"YES\n";
      }else{
          cout<<"NO\n";
      }
    }
    return 0;
}