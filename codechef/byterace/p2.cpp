#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int ptr[26] = {0};
void display(){
 for(int i=0;i<26;i++){
                   for(int j=0;j<ptr[i];j++){
                    cout<<char(i+ 'a');
                   }
               }
               cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       int temp = k;
       
       for(int i=0;i<26;i++){
           ptr[i] = 0;
       }
       int count = 0;
       int i = 0;
       while((1<<i)<=temp){
           if((1<<i) & temp){
               ptr[i]++;
               count++;
           }
           i++;
       }
       
       if(count>n){
           cout<<-1<<endl;
           continue;
       }else{
           
           int leftlength = n - count;
        //    cout<<leftlength<<" ";
        //    display();
           int i = 25;
           while(leftlength!=0 && i>0){
              
               while(leftlength && ptr[i]){
                   ptr[i]--;
                   ptr[i-1]+=2;
                   leftlength--;
               }
               i--;
           }
           if(leftlength!=0){
               cout<<-1<<endl;
           }else{
              display();
           }
       }
    }
    return 0;
}