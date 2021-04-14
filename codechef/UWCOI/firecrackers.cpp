#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       int count = 0;
       for(int i=0;i<n && count>=0;i++){
           int temp;
           cin>>temp;
           if(temp==0){
               count--;
           }else{
               count++;
           }
       }
       if(count<0){
           cout<<"Invalid\n";
       }else{
           cout<<"Valid\n";
       }
    }
    return 0;
}