#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       int count = 0;
       int lbrac = 0;
       int lround = 0;

       for(int i=0;i<s.size();i++){
           if(s[i]=='('){
               lbrac++;
           }else if(s[i]==')'){
               if(lbrac){
                   count++;
                   lbrac--;
               }
           }else if(s[i] =='['){
               lround++;
           }else{
               if(lround){
                   count++;
                   lround--;
               }
           }
       }
       cout<<count<<endl;
    }
}